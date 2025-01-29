#ifndef MORAC_STATE_H
#define MORAC_STATE_H

#include "chartype.h"

typedef enum
{
  STATE_START,         // Initial state
  STATE_IDENTIFIER,    // Processing identifier
  STATE_NUMBER,        // Processing number
  STATE_FLOAT,         // Processing float number
  STATE_OPERATOR,      // Processing operator
  STATE_CHAR,          // Processing char literal
  STATE_STRING,        // Processing string literal
  STATE_SLASH,         // Encountered '/', might be comment
  STATE_LINE_COMMENT,  // Processing line comment
  STATE_BLOCK_COMMENT, // Processing block comment
  STATE_DONE,          // End of token
  STATE_ERROR          // Error state
} LexerState;

// State transition function type
typedef LexerState (*StateTransitionFn)(char c);

// State transition table
extern LexerState state_transitions[12][17]; // [STATE_COUNT][CHAR_TYPE_COUNT]

// Function declarations
LexerState get_next_state(LexerState current_state, CharType input);
int is_final_state(LexerState state);
const char *state_to_string(LexerState state);

#endif