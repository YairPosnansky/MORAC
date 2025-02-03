#include "token.h"
#include <stdio.h>
#include <string.h>

Token *create_token(TokenType type, const char *lexeme, int line, int column) {
  Token *token = (Token *)malloc(sizeof(Token));
  if (!token) {
    return NULL;
  }

  token->type = type;
  token->line = line;
  token->column = column;

  if (lexeme) {
    strncpy(token->lexeme, lexeme, MAX_LEXEME_LENGTH - 1);
    token->lexeme[MAX_LEXEME_LENGTH - 1] = '\0';
  } else {
    token->lexeme[0] = '\0';
  }

  return token;
}
void free_token(Token *token) {
  if (token) {
    free(token);
  }
}

const char *get_token_name(TokenType type) {
  switch (type) {
  case TOKEN_EOF:
    return "EOF";
  case TOKEN_INT:
    return "INT";
  case TOKEN_CHAR:
    return "CHAR";
  case TOKEN_FLOAT:
    return "FLOAT";
  case TOKEN_VOID:
    return "VOID";
  case TOKEN_IF:
    return "IF";
  case TOKEN_ELSE:
    return "ELSE";
  case TOKEN_WHILE:
    return "WHILE";
  case TOKEN_FOR:
    return "FOR";
  case TOKEN_RETURN:
    return "RETURN";
  case TOKEN_IDENTIFIER:
    return "IDENTIFIER";
  case TOKEN_INTEGER_LIT:
    return "INTEGER";
  case TOKEN_FLOAT_LIT:
    return "FLOAT_LIT";
  case TOKEN_CHAR_LIT:
    return "CHAR_LIT";
  case TOKEN_STRING_LIT:
    return "STRING_LIT";
  case TOKEN_PLUS:
    return "PLUS";
  case TOKEN_MINUS:
    return "MINUS";
  case TOKEN_MULTIPLY:
    return "MULTIPLY";
  case TOKEN_DIVIDE:
    return "DIVIDE";
  case TOKEN_MODULO:
    return "MODULO";
  case TOKEN_ASSIGN:
    return "ASSIGN";
  case TOKEN_PLUS_ASSIGN:
    return "PLUS_ASSIGN";
  case TOKEN_MINUS_ASSIGN:
    return "MINUS_ASSIGN";
  case TOKEN_MUL_ASSIGN:
    return "MUL_ASSIGN";
  case TOKEN_DIV_ASSIGN:
    return "DIV_ASSIGN";
  case TOKEN_MOD_ASSIGN:
    return "MOD_ASSIGN";
  case TOKEN_EQUAL:
    return "EQUAL";
  case TOKEN_NOT_EQUAL:
    return "NOT_EQUAL";
  case TOKEN_LESS:
    return "LESS";
  case TOKEN_LESS_EQUAL:
    return "LESS_EQUAL";
  case TOKEN_GREATER:
    return "GREATER";
  case TOKEN_GREATER_EQUAL:
    return "GREATER_EQUAL";
  case TOKEN_AND:
    return "AND";
  case TOKEN_OR:
    return "OR";
  case TOKEN_NOT:
    return "NOT";
  case TOKEN_INCREMENT:
    return "INCREMENT";
  case TOKEN_DECREMENT:
    return "DECREMENT";
  case TOKEN_POINTER:
    return "POINTER";
  case TOKEN_ADDRESS:
    return "ADDRESS";
  case TOKEN_LPAREN:
    return "LPAREN";
  case TOKEN_RPAREN:
    return "RPAREN";
  case TOKEN_LBRACE:
    return "LBRACE";
  case TOKEN_RBRACE:
    return "RBRACE";
  case TOKEN_LBRACKET:
    return "LBRACKET";
  case TOKEN_RBRACKET:
    return "RBRACKET";
  case TOKEN_SEMICOLON:
    return "SEMICOLON";
  case TOKEN_COMMA:
    return "COMMA";
  case TOKEN_ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}

TokenType get_keyword_token(const char *lexeme) {
  for (int i = 0; keywords[i].keyword != NULL; i++) {
    if (strcmp(keywords[i].keyword, lexeme) == 0) {
      return keywords[i].type;
    }
  }
  return TOKEN_IDENTIFIER;
}