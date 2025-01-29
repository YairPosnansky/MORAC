#include "lexer/state.h"

// State transition table - static definition
LexerState state_transitions[12][17] = {
    // STATE_START
    {
        /*CHAR_LETTER*/ STATE_IDENTIFIER,
        /*CHAR_DIGIT*/ STATE_NUMBER,
        /*CHAR_OPERATOR*/ STATE_OPERATOR,
        /*CHAR_SPACE*/ STATE_START,
        /*CHAR_QUOTE*/ STATE_STRING,
        /*CHAR_SLASH*/ STATE_SLASH,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_ERROR,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_IDENTIFIER
    {
        /*CHAR_LETTER*/ STATE_IDENTIFIER,
        /*CHAR_DIGIT*/ STATE_IDENTIFIER,
        /*CHAR_OPERATOR*/ STATE_DONE,
        /*CHAR_SPACE*/ STATE_DONE,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_DONE,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_DONE,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_NUMBER
    {
        /*CHAR_LETTER*/ STATE_ERROR,
        /*CHAR_DIGIT*/ STATE_NUMBER,
        /*CHAR_OPERATOR*/ STATE_DONE,
        /*CHAR_SPACE*/ STATE_DONE,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_DONE,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_FLOAT,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_FLOAT
    {
        /*CHAR_LETTER*/ STATE_ERROR,
        /*CHAR_DIGIT*/ STATE_FLOAT,
        /*CHAR_OPERATOR*/ STATE_DONE,
        /*CHAR_SPACE*/ STATE_DONE,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_DONE,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_ERROR,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_OPERATOR
    {
        /*CHAR_LETTER*/ STATE_DONE,
        /*CHAR_DIGIT*/ STATE_DONE,
        /*CHAR_OPERATOR*/ STATE_OPERATOR,
        /*CHAR_SPACE*/ STATE_DONE,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_DONE,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_DONE,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_CHAR
    {
        /*CHAR_LETTER*/ STATE_CHAR,
        /*CHAR_DIGIT*/ STATE_CHAR,
        /*CHAR_OPERATOR*/ STATE_CHAR,
        /*CHAR_SPACE*/ STATE_CHAR,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_CHAR,
        /*CHAR_LPAREN*/ STATE_CHAR,
        /*CHAR_RPAREN*/ STATE_CHAR,
        /*CHAR_LBRACE*/ STATE_CHAR,
        /*CHAR_RBRACE*/ STATE_CHAR,
        /*CHAR_LBRACKET*/ STATE_CHAR,
        /*CHAR_RBRACKET*/ STATE_CHAR,
        /*CHAR_SEMICOLON*/ STATE_CHAR,
        /*CHAR_COMMA*/ STATE_CHAR,
        /*CHAR_DOT*/ STATE_CHAR,
        /*CHAR_OTHER*/ STATE_CHAR,
        /*CHAR_EOF*/ STATE_ERROR},

    // STATE_STRING
    {
        /*CHAR_LETTER*/ STATE_STRING,
        /*CHAR_DIGIT*/ STATE_STRING,
        /*CHAR_OPERATOR*/ STATE_STRING,
        /*CHAR_SPACE*/ STATE_STRING,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_STRING,
        /*CHAR_LPAREN*/ STATE_STRING,
        /*CHAR_RPAREN*/ STATE_STRING,
        /*CHAR_LBRACE*/ STATE_STRING,
        /*CHAR_RBRACE*/ STATE_STRING,
        /*CHAR_LBRACKET*/ STATE_STRING,
        /*CHAR_RBRACKET*/ STATE_STRING,
        /*CHAR_SEMICOLON*/ STATE_STRING,
        /*CHAR_COMMA*/ STATE_STRING,
        /*CHAR_DOT*/ STATE_STRING,
        /*CHAR_OTHER*/ STATE_STRING,
        /*CHAR_EOF*/ STATE_ERROR},

    // STATE_SLASH
    {
        /*CHAR_LETTER*/ STATE_DONE,
        /*CHAR_DIGIT*/ STATE_DONE,
        /*CHAR_OPERATOR*/ STATE_OPERATOR,
        /*CHAR_SPACE*/ STATE_DONE,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_LINE_COMMENT,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_DONE,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_LINE_COMMENT
    {
        /*CHAR_LETTER*/ STATE_LINE_COMMENT,
        /*CHAR_DIGIT*/ STATE_LINE_COMMENT,
        /*CHAR_OPERATOR*/ STATE_LINE_COMMENT,
        /*CHAR_SPACE*/ STATE_LINE_COMMENT,
        /*CHAR_QUOTE*/ STATE_LINE_COMMENT,
        /*CHAR_SLASH*/ STATE_LINE_COMMENT,
        /*CHAR_LPAREN*/ STATE_LINE_COMMENT,
        /*CHAR_RPAREN*/ STATE_LINE_COMMENT,
        /*CHAR_LBRACE*/ STATE_LINE_COMMENT,
        /*CHAR_RBRACE*/ STATE_LINE_COMMENT,
        /*CHAR_LBRACKET*/ STATE_LINE_COMMENT,
        /*CHAR_RBRACKET*/ STATE_LINE_COMMENT,
        /*CHAR_SEMICOLON*/ STATE_LINE_COMMENT,
        /*CHAR_COMMA*/ STATE_LINE_COMMENT,
        /*CHAR_DOT*/ STATE_LINE_COMMENT,
        /*CHAR_OTHER*/ STATE_LINE_COMMENT,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_BLOCK_COMMENT
    {
        /*CHAR_LETTER*/ STATE_BLOCK_COMMENT,
        /*CHAR_DIGIT*/ STATE_BLOCK_COMMENT,
        /*CHAR_OPERATOR*/ STATE_BLOCK_COMMENT,
        /*CHAR_SPACE*/ STATE_BLOCK_COMMENT,
        /*CHAR_QUOTE*/ STATE_BLOCK_COMMENT,
        /*CHAR_SLASH*/ STATE_BLOCK_COMMENT,
        /*CHAR_LPAREN*/ STATE_BLOCK_COMMENT,
        /*CHAR_RPAREN*/ STATE_BLOCK_COMMENT,
        /*CHAR_LBRACE*/ STATE_BLOCK_COMMENT,
        /*CHAR_RBRACE*/ STATE_BLOCK_COMMENT,
        /*CHAR_LBRACKET*/ STATE_BLOCK_COMMENT,
        /*CHAR_RBRACKET*/ STATE_BLOCK_COMMENT,
        /*CHAR_SEMICOLON*/ STATE_BLOCK_COMMENT,
        /*CHAR_COMMA*/ STATE_BLOCK_COMMENT,
        /*CHAR_DOT*/ STATE_BLOCK_COMMENT,
        /*CHAR_OTHER*/ STATE_BLOCK_COMMENT,
        /*CHAR_EOF*/ STATE_ERROR},

    // STATE_DONE
    {
        /*CHAR_LETTER*/ STATE_DONE,
        /*CHAR_DIGIT*/ STATE_DONE,
        /*CHAR_OPERATOR*/ STATE_DONE,
        /*CHAR_SPACE*/ STATE_DONE,
        /*CHAR_QUOTE*/ STATE_DONE,
        /*CHAR_SLASH*/ STATE_DONE,
        /*CHAR_LPAREN*/ STATE_DONE,
        /*CHAR_RPAREN*/ STATE_DONE,
        /*CHAR_LBRACE*/ STATE_DONE,
        /*CHAR_RBRACE*/ STATE_DONE,
        /*CHAR_LBRACKET*/ STATE_DONE,
        /*CHAR_RBRACKET*/ STATE_DONE,
        /*CHAR_SEMICOLON*/ STATE_DONE,
        /*CHAR_COMMA*/ STATE_DONE,
        /*CHAR_DOT*/ STATE_DONE,
        /*CHAR_OTHER*/ STATE_DONE,
        /*CHAR_EOF*/ STATE_DONE},

    // STATE_ERROR
    {
        /*CHAR_LETTER*/ STATE_ERROR,
        /*CHAR_DIGIT*/ STATE_ERROR,
        /*CHAR_OPERATOR*/ STATE_ERROR,
        /*CHAR_SPACE*/ STATE_ERROR,
        /*CHAR_QUOTE*/ STATE_ERROR,
        /*CHAR_SLASH*/ STATE_ERROR,
        /*CHAR_LPAREN*/ STATE_ERROR,
        /*CHAR_RPAREN*/ STATE_ERROR,
        /*CHAR_LBRACE*/ STATE_ERROR,
        /*CHAR_RBRACE*/ STATE_ERROR,
        /*CHAR_LBRACKET*/ STATE_ERROR,
        /*CHAR_RBRACKET*/ STATE_ERROR,
        /*CHAR_SEMICOLON*/ STATE_ERROR,
        /*CHAR_COMMA*/ STATE_ERROR,
        /*CHAR_DOT*/ STATE_ERROR,
        /*CHAR_OTHER*/ STATE_ERROR,
        /*CHAR_EOF*/ STATE_ERROR}};

LexerState get_next_state(LexerState current_state, CharType input)
{
  // Bounds checking
  if (current_state < 0 || current_state >= 12 || input < 0 || input >= 17)
  {
    return STATE_ERROR;
  }
  return state_transitions[current_state][input];
}

int is_final_state(LexerState state)
{
  return (state == STATE_DONE || state == STATE_ERROR);
}

const char *state_to_string(LexerState state)
{
  switch (state)
  {
  case STATE_START:
    return "START";
  case STATE_IDENTIFIER:
    return "IDENTIFIER";
  case STATE_NUMBER:
    return "NUMBER";
  case STATE_FLOAT:
    return "FLOAT";
  case STATE_OPERATOR:
    return "OPERATOR";
  case STATE_CHAR:
    return "CHAR";
  case STATE_STRING:
    return "STRING";
  case STATE_SLASH:
    return "SLASH";
  case STATE_LINE_COMMENT:
    return "LINE_COMMENT";
  case STATE_BLOCK_COMMENT:
    return "BLOCK_COMMENT";
  case STATE_DONE:
    return "DONE";
  case STATE_ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}