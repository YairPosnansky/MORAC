#ifndef MORAC_STATE_H
#define MORAC_STATE_H

#include "chartype.h"

#define STATE_COUNT 12

typedef enum {
  STATE_START,
  STATE_IDENTIFIER,
  STATE_NUMBER,
  STATE_FLOAT,
  STATE_OPERATOR,
  STATE_CHAR,
  STATE_STRING,
  STATE_SLASH,
  STATE_LINE_COMMENT,
  STATE_BLOCK_COMMENT,
  // Final States
  STATE_DONE,
  STATE_ERROR
} LexerState;

// State transition function type
typedef LexerState (*StateTransitionFn)(char c);

// State transition table
extern LexerState state_transitions[STATE_COUNT][CHAR_TYPE_COUNT];

// Function declarations
LexerState get_next_state(LexerState current_state, CharType input);
int is_final_state(LexerState state);
const char *state_to_string(LexerState state);

#endif