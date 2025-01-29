#ifndef MORAC_STATE_UTILS_H
#define MORAC_STATE_UTILS_H

#include "state.h"
#include "token.h"

// Compound operators
int is_compound_operator(char current, char next);
TokenType get_compound_operator_type(char first, char next);

// Comment handling
int is_block_comment_end(char current, char next);
void skip_line_comment(char **source);
void skip_block_comment(char **source);

// String/Char literal handling
int is_escape_sequence(char next);
char process_escape_sequence(char next);

// Number validation
int is_valid_number_format(const char *lexeme);
int is_valid_float_format(const char *lexeme);

// State context
typedef struct
{
  char *position;
  int line;
  int column;
  LexerState state;
} StateContext;

void save_state(StateContext *context, char *position, int line, int column,
                LexerState state);
void restore_state(StateContext *context, char **position, int *line,
                   int *column, LexerState *state);

#endif