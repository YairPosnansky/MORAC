#include "lexer/chartype.h"

int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

int is_digit(char c) { return c >= '0' && c <= '9'; }

int is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '%' || c == '=' || c == '<' ||
         c == '>' || c == '!' || c == '&' || c == '|' || c == '^';
}

int is_space(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }

int is_single_quote(char c) { return c == '\''; }
int is_double_quote(char c) { return c == '"'; }

CharType get_char_type(char c) {
  if (c == EOF || c == '\0')
    return CHAR_EOF;
  if (is_letter(c))
    return CHAR_LETTER;
  if (is_digit(c))
    return CHAR_DIGIT;
  if (is_operator(c))
    return CHAR_OPERATOR;
  if (is_space(c))
    return CHAR_SPACE;
  if (is_single_quote(c))
    return CHAR_SINGLE_QUOTE;
  if (is_double_quote(c))
    return CHAR_DOUBLE_QUOTE;
  switch (c) {
  case '/':
    return CHAR_SLASH;
  case '(':
    return CHAR_LPAREN;
  case ')':
    return CHAR_RPAREN;
  case '{':
    return CHAR_LBRACE;
  case '}':
    return CHAR_RBRACE;
  case '[':
    return CHAR_LBRACKET;
  case ']':
    return CHAR_RBRACKET;
  case ';':
    return CHAR_SEMICOLON;
  case ',':
    return CHAR_COMMA;
  case '.':
    return CHAR_DOT;
  default:
    return CHAR_OTHER;
  }
}