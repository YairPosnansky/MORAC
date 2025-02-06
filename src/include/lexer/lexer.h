#ifndef MORAC_LEXER_H
#define MORAC_LEXER_H

#include "lexer/state.h"
#include "lexer/state_utils.h"
#include "token.h"
#include <stdio.h>

typedef struct {
  char *source;
  char *current;
  int line;
  int column;
  char *lexeme_start;
} Lexer;

Lexer *lexer_create(const char *source);
void lexer_destroy(Lexer *lexer);

Token *lexer_next_token(Lexer *lexer);
void lexer_error(Lexer *lexer, const char *message);

void lexer_skip_whitespace(Lexer *lexer);
char lexer_peek(Lexer *lexer);
char lexer_peek_next(Lexer *lexer);
char lexer_advance(Lexer *lexer);
int lexer_is_at_end(Lexer *lexer);
Token *lexer_make_token(Lexer *lexer, TokenType type);

#endif