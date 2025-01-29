#ifndef MORAC_TOKEN_H
#define MORAC_TOKEN_H

#include <stdlib.h>

typedef enum {
  TOKEN_EOF,

  TOKEN_INT,
  TOKEN_CHAR,
  TOKEN_FLOAT,
  TOKEN_VOID,

  TOKEN_IF,
  TOKEN_ELSE,
  TOKEN_WHILE,
  TOKEN_FOR,
  TOKEN_RETURN,

  TOKEN_IDENTIFIER,
  TOKEN_INTEGER_LIT,
  TOKEN_FLOAT_LIT,
  TOKEN_CHAR_LIT,
  TOKEN_STRING_LIT,

  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_MULTIPLY,
  TOKEN_DIVIDE,
  TOKEN_MODULO,

  TOKEN_ASSIGN,
  TOKEN_PLUS_ASSIGN,
  TOKEN_MINUS_ASSIGN,
  TOKEN_MUL_ASSIGN,
  TOKEN_DIV_ASSIGN,
  TOKEN_MOD_ASSIGN,

  TOKEN_EQUAL,
  TOKEN_NOT_EQUAL,
  TOKEN_LESS,
  TOKEN_LESS_EQUAL,
  TOKEN_GREATER,
  TOKEN_GREATER_EQUAL,

  TOKEN_AND,
  TOKEN_OR,
  TOKEN_NOT,

  TOKEN_INCREMENT,
  TOKEN_DECREMENT,

  TOKEN_POINTER,
  TOKEN_ADDRESS,

  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_LBRACE,
  TOKEN_RBRACE,
  TOKEN_LBRACKET,
  TOKEN_RBRACKET,
  TOKEN_SEMICOLON,
  TOKEN_COMMA,

  TOKEN_ERROR
} TokenType;

#define MAX_LEXEME_LENGTH 256

typedef struct {
  TokenType type;
  char lexeme[MAX_LEXEME_LENGTH];
  int line;
  int column;
} Token;

typedef struct {
  const char *keyword;
  TokenType type;
} Keyword;

static const Keyword keywords[] = {
    {"int", TOKEN_INT},     {"char", TOKEN_CHAR}, {"float", TOKEN_FLOAT},
    {"void", TOKEN_VOID},   {"if", TOKEN_IF},     {"else", TOKEN_ELSE},
    {"while", TOKEN_WHILE}, {"for", TOKEN_FOR},   {"return", TOKEN_RETURN},
    {NULL, TOKEN_ERROR}};

Token *create_token(TokenType type, const char *lexeme, int line, int column);
void free_token(Token *token);
const char *get_token_name(TokenType type);
TokenType get_keyword_token(const char *lexeme);

#endif