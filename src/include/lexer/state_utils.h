#ifndef MORAC_STATE_UTILS_H
#define MORAC_STATE_UTILS_H

#include "state.h"
#include "token.h"

int is_compound_operator(char current, char next);
TokenType get_compound_operator_type(char first, char next);

void skip_line_comment(char **source);
void skip_block_comment(char **source);

int is_escape_sequence(char next);

#endif