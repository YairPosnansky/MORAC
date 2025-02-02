#include <stdlib.h>
#include <string.h>
#include "lexer/lexer.h"
#include "lexer/chartype.h"

Lexer *lexer_create(const char *source)
{
  Lexer *lexer = (Lexer *)malloc(sizeof(Lexer));
  if (!lexer)
    return NULL;

  size_t len = strlen(source) + 1;
  lexer->source = (char *)malloc(len);
  if (!lexer->source)
  {
    free(lexer);
    return NULL;
  }
  strcpy(lexer->source, source);

  lexer->current = lexer->source;
  lexer->lexeme_start = lexer->current;
  lexer->line = 1;
  lexer->column = 1;

  return lexer;
}

void lexer_destroy(Lexer *lexer)
{
  if (lexer)
  {
    if (lexer->source)
    {
      free(lexer->source);
    }
    free(lexer);
  }
}

void lexer_skip_whitespace(Lexer *lexer)
{
  while (1)
  {
    char c = lexer_peek(lexer);
    switch (c)
    {
    case ' ':
    case '\t':
      lexer->column++;
      lexer_advance(lexer);
      break;
    case '\n':
      lexer->line++;
      lexer->column = 1;
      lexer_advance(lexer);
      break;
    case '\r':
      lexer_advance(lexer);
      if (lexer_peek(lexer) == '\n')
      {
        lexer_advance(lexer);
      }
      lexer->line++;
      lexer->column = 1;
      break;
    default:
      return;
    }
  }
}

char lexer_peek(Lexer *lexer)
{
  if (lexer_is_at_end(lexer))
    return '\0';
  return *lexer->current;
}

char lexer_peek_next(Lexer *lexer)
{
  if (lexer_is_at_end(lexer))
    return '\0';
  return lexer->current[1];
}

char lexer_advance(Lexer *lexer)
{
  if (!lexer_is_at_end(lexer))
  {
    lexer->current++;
    return lexer->current[-1];
  }
  return '\0';
}

int lexer_is_at_end(Lexer *lexer)
{
  return *lexer->current == '\0';
}

Token *lexer_make_token(Lexer *lexer, TokenType type)
{
  Token *token = create_token(type, NULL, lexer->line, lexer->column);
  if (!token)
    return NULL;

  // Calculate lexeme length
  size_t length = lexer->current - lexer->lexeme_start;
  if (length >= MAX_LEXEME_LENGTH)
    length = MAX_LEXEME_LENGTH - 1;

  // Copy lexeme
  strncpy(token->lexeme, lexer->lexeme_start, length);
  token->lexeme[length] = '\0';

  return token;
}

void lexer_error(Lexer *lexer, const char *message)
{
  fprintf(stderr, "[line %d:%d] Error: %s\n", lexer->line, lexer->column, message);
}

Token *lexer_next_token(Lexer *lexer)
{
  lexer_skip_whitespace(lexer);
  lexer->lexeme_start = lexer->current;

  if (lexer_is_at_end(lexer))
  {
    return lexer_make_token(lexer, TOKEN_EOF);
  }

  char c = lexer_advance(lexer);
  CharType char_type = get_char_type(c);
  LexerState state = STATE_START;

  while (!is_final_state(state))
  {
    state = get_next_state(state, char_type);

    switch (state)
    {
    case STATE_START:
    {
      c = lexer_advance(lexer);
      char_type = get_char_type(c);
      break;
    }

    case STATE_IDENTIFIER:
    {
      while (is_letter(lexer_peek(lexer)) || is_digit(lexer_peek(lexer)))
      {
        lexer_advance(lexer);
      }

      size_t length = lexer->current - lexer->lexeme_start;
      char temp[MAX_LEXEME_LENGTH];
      strncpy(temp, lexer->lexeme_start, length);
      temp[length] = '\0';

      TokenType type = get_keyword_token(temp);
      return lexer_make_token(lexer, type);
    }

    case STATE_NUMBER:
    {
      while (is_digit(lexer_peek(lexer)))
      {
        lexer_advance(lexer);
      }

      if (lexer_peek(lexer) == '.' && is_digit(lexer_peek_next(lexer)))
      {
        lexer_advance(lexer);
        while (is_digit(lexer_peek(lexer)))
        {
          lexer_advance(lexer);
        }
        return lexer_make_token(lexer, TOKEN_FLOAT_LIT);
      }

      return lexer_make_token(lexer, TOKEN_INTEGER_LIT);
    }

    case STATE_STRING:
    {
      while (lexer_peek(lexer) != '"' && !lexer_is_at_end(lexer))
      {
        if (lexer_peek(lexer) == '\\' && is_escape_sequence(lexer_peek_next(lexer)))
        {
          lexer_advance(lexer);
          lexer_advance(lexer);
        }
        else
        {
          lexer_advance(lexer);
        }
      }

      if (lexer_is_at_end(lexer))
      {
        lexer_error(lexer, "Unterminated string.");
        return lexer_make_token(lexer, TOKEN_ERROR);
      }

      lexer_advance(lexer);
      return lexer_make_token(lexer, TOKEN_STRING_LIT);
    }

    case STATE_OPERATOR:
    {
      if (is_compound_operator(c, lexer_peek(lexer)))
      {
        char next = lexer_advance(lexer);
        return lexer_make_token(lexer, get_compound_operator_type(c, next));
      }

      TokenType type;
      switch (c)
      {
      case '+':
        type = TOKEN_PLUS;
        break;
      case '-':
        type = TOKEN_MINUS;
        break;
      case '*':
        type = TOKEN_MULTIPLY;
        break;
      case '/':
        type = TOKEN_DIVIDE;
        break;
      case '%':
        type = TOKEN_MODULO;
        break;
      case '=':
        type = TOKEN_ASSIGN;
        break;
      case '<':
        type = TOKEN_LESS;
        break;
      case '>':
        type = TOKEN_GREATER;
        break;
      case '!':
        type = TOKEN_NOT;
        break;
      default:
        type = TOKEN_ERROR;
      }
      return lexer_make_token(lexer, type);
    }

    case STATE_SLASH:
    {
      if (lexer_peek(lexer) == '/')
      {
        skip_line_comment(&lexer->current);
        return lexer_next_token(lexer);
      }
      if (lexer_peek(lexer) == '*')
      {
        skip_block_comment(&lexer->current);
        return lexer_next_token(lexer);
      }
      return lexer_make_token(lexer, TOKEN_DIVIDE);
    }

    case STATE_ERROR:
    {
      lexer_error(lexer, "Invalid character.");
      return lexer_make_token(lexer, TOKEN_ERROR);
    }

    case STATE_DONE:
    {
      switch (c)
      {
      case '(':
        return lexer_make_token(lexer, TOKEN_LPAREN);
      case ')':
        return lexer_make_token(lexer, TOKEN_RPAREN);
      case '{':
        return lexer_make_token(lexer, TOKEN_LBRACE);
      case '}':
        return lexer_make_token(lexer, TOKEN_RBRACE);
      case '[':
        return lexer_make_token(lexer, TOKEN_LBRACKET);
      case ']':
        return lexer_make_token(lexer, TOKEN_RBRACKET);
      case ';':
        return lexer_make_token(lexer, TOKEN_SEMICOLON);
      case ',':
        return lexer_make_token(lexer, TOKEN_COMMA);
      default:
        return lexer_make_token(lexer, TOKEN_ERROR);
      }
    }

    case STATE_FLOAT:
    case STATE_CHAR:
    {
      char quote_type = lexer->lexeme_start[0];

      if (quote_type == '\'')
      {
        lexer_advance(lexer);

        if (lexer_peek(lexer) == '\\')
        {
          lexer_advance(lexer);
          if (!is_escape_sequence(lexer_peek(lexer)))
          {
            lexer_error(lexer, "Invalid escape sequence");
            return lexer_make_token(lexer, TOKEN_ERROR);
          }
          lexer_advance(lexer);
        }
        else
        {
          lexer_advance(lexer);
        }

        if (lexer_peek(lexer) != '\'')
        {
          lexer_error(lexer, "Character literal must contain exactly one character");
          return lexer_make_token(lexer, TOKEN_ERROR);
        }
        lexer_advance(lexer);
        return lexer_make_token(lexer, TOKEN_CHAR_LIT);
      }
      else if (quote_type == '"')
      {
        while (lexer_peek(lexer) != '"' && !lexer_is_at_end(lexer))
        {
          if (lexer_peek(lexer) == '\\')
          {
            lexer_advance(lexer);
            if (!is_escape_sequence(lexer_peek(lexer)))
            {
              lexer_error(lexer, "Invalid escape sequence");
              return lexer_make_token(lexer, TOKEN_ERROR);
            }
            lexer_advance(lexer);
          }
          else
          {
            lexer_advance(lexer);
          }
        }

        if (lexer_is_at_end(lexer))
        {
          lexer_error(lexer, "Unterminated string");
          return lexer_make_token(lexer, TOKEN_ERROR);
        }

        lexer_advance(lexer);
        return lexer_make_token(lexer, TOKEN_STRING_LIT);
      }
      break;
    }
    case STATE_LINE_COMMENT:
    case STATE_BLOCK_COMMENT:
      break;

    default:
      lexer_error(lexer, "Invalid state encountered.");
      return lexer_make_token(lexer, TOKEN_ERROR);
    }
  }
  lexer_error(lexer, "Unexpected end of token processing");
  return lexer_make_token(lexer, TOKEN_ERROR);
}