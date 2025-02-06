#include "../../include/lexer/state_utils.h"
#include <ctype.h>
#include <string.h>

int is_compound_operator(char current, char next) {
  switch (current) {
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

TokenType get_compound_operator_type(char first, char next) {
  switch (first) {
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

int is_block_comment_end(char current, char next) {
  return current == '*' && next == '/';
}

void skip_line_comment(char **source) {
  while (**source != '\n' && **source != '\0') {
    (*source)++;
  }
  if (**source == '\n') {
    (*source)++;
  }
}

void skip_block_comment(char **source) {
  int nesting = 1; // Current comment level

  while (nesting > 0 && **source != '\0') {
    char current = **source;
    (*source)++;

    if (current == '/' && **source == '*') {
      nesting++;
      (*source)++;
    } else if (current == '*' && **source == '/') {
      nesting--;
      (*source)++;
    }
  }
}

int is_escape_sequence(char next) {
  return next == 'n' || next == 't' || next == 'r' || next == '\\' ||
         next == '\'' || next == '\"';
}
