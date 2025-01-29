#ifndef MORAC_LEXER_H
#define MORAC_LEXER_H

#include <stdio.h>
#include "token.h"
#include "lexer/state.h"
#include "lexer/state_utils.h"

typedef struct
{
  char *source;         // Source code buffer
  char *current;        // Current position in source
  int line;             // Current line number
  int column;           // Current column number
  StateContext context; // For backtracking
  char *lexeme_start;   // Start of current lexeme
} Lexer;

// Lexer lifecycle
Lexer *lexer_create(const char *source);
void lexer_destroy(Lexer *lexer);

// Token operations
Token *lexer_next_token(Lexer *lexer);
void lexer_error(Lexer *lexer, const char *message);

// Helper functions
void lexer_skip_whitespace(Lexer *lexer);
char lexer_peek(Lexer *lexer);
char lexer_peek_next(Lexer *lexer);
char lexer_advance(Lexer *lexer);
int lexer_is_at_end(Lexer *lexer);
Token *lexer_make_token(Lexer *lexer, TokenType type);

#endif