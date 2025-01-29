#include <string.h>
#include <ctype.h>
#include "../../include/lexer/state_utils.h"

// Compound operator handling
int is_compound_operator(char current, char next)
{
  switch (current)
  {
  case '+':
    return next == '+' || next == '=';
  case '-':
    return next == '-' || next == '=';
  case '*':
    return next == '=';
  case '/':
    return next == '=' || next == '/' || next == '*';
  case '=':
    return next == '=';
  case '!':
    return next == '=';
  case '<':
    return next == '=';
  case '>':
    return next == '=';
  case '&':
    return next == '&';
  case '|':
    return next == '|';
  default:
    return 0;
  }
}

TokenType get_compound_operator_type(char first, char next)
{
  switch (first)
  {
  case '+':
    if (next == '+')
      return TOKEN_INCREMENT;
    if (next == '=')
      return TOKEN_PLUS_ASSIGN;
    break;
  case '-':
    if (next == '-')
      return TOKEN_DECREMENT;
    if (next == '=')
      return TOKEN_MINUS_ASSIGN;
    break;
  case '*':
    if (next == '=')
      return TOKEN_MUL_ASSIGN;
    break;
  case '/':
    if (next == '=')
      return TOKEN_DIV_ASSIGN;
    break;
  case '=':
    if (next == '=')
      return TOKEN_EQUAL;
    break;
  case '!':
    if (next == '=')
      return TOKEN_NOT_EQUAL;
    break;
  case '<':
    if (next == '=')
      return TOKEN_LESS_EQUAL;
    break;
  case '>':
    if (next == '=')
      return TOKEN_GREATER_EQUAL;
    break;
  case '&':
    if (next == '&')
      return TOKEN_AND;
    break;
  case '|':
    if (next == '|')
      return TOKEN_OR;
    break;
  }
  return TOKEN_ERROR;
}

// Comment handling
int is_block_comment_end(char current, char next)
{
  return current == '*' && next == '/';
}

void skip_line_comment(char **source)
{
  while (**source != '\n' && **source != '\0')
  {
    (*source)++;
  }
  if (**source == '\n')
  {
    (*source)++;
  }
}

void skip_block_comment(char **source)
{
  int nesting = 1; // Current comment level

  while (nesting > 0 && **source != '\0')
  {
    char current = **source;
    (*source)++;

    if (current == '/' && **source == '*')
    {
      nesting++;
      (*source)++;
    }
    else if (current == '*' && **source == '/')
    {
      nesting--;
      (*source)++;
    }
  }
}

// String/Char literal handling
int is_escape_sequence(char next)
{
  return next == 'n' || next == 't' || next == 'r' ||
         next == '\\' || next == '\'' || next == '\"';
}

char process_escape_sequence(char next)
{
  switch (next)
  {
  case 'n':
    return '\n';
  case 't':
    return '\t';
  case 'r':
    return '\r';
  case '\\':
    return '\\';
  case '\'':
    return '\'';
  case '\"':
    return '\"';
  default:
    return next;
  }
}

// Number validation
int is_valid_number_format(const char *lexeme)
{
  // Check if empty
  if (!lexeme || !*lexeme)
    return 0;

  // First character must be digit
  if (!isdigit(*lexeme))
    return 0;

  // Check remaining characters
  while (*++lexeme)
  {
    if (!isdigit(*lexeme))
      return 0;
  }

  return 1;
}

int is_valid_float_format(const char *lexeme)
{
  // Check if empty
  if (!lexeme || !*lexeme)
    return 0;

  // First character must be digit
  if (!isdigit(*lexeme))
    return 0;

  int decimal_points = 0;

  // Check remaining characters
  while (*++lexeme)
  {
    if (*lexeme == '.')
    {
      decimal_points++;
      if (decimal_points > 1)
        return 0;
    }
    else if (!isdigit(*lexeme))
    {
      return 0;
    }
  }

  // Must have exactly one decimal point
  return decimal_points == 1;
}

// State context management
void save_state(StateContext *context, char *position, int line, int column, LexerState state)
{
  if (context)
  {
    context->position = position;
    context->line = line;
    context->column = column;
    context->state = state;
  }
}

void restore_state(StateContext *context, char **position, int *line, int *column, LexerState *state)
{
  if (context)
  {
    *position = context->position;
    *line = context->line;
    *column = context->column;
    *state = context->state;
  }
}