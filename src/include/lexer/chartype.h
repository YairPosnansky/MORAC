#ifndef MORAC_CHARTYPE_H
#define MORAC_CHARTYPE_H

#include <stdio.h>

#define CHAR_TYPE_COUNT 18

typedef enum {
  CHAR_LETTER,       // [a-zA-Z_]
  CHAR_DIGIT,        // [0-9]
  CHAR_OPERATOR,     // + - * / % = < > ! & | ^
  CHAR_SPACE,        // space, tab, newline, carriage return
  CHAR_SINGLE_QUOTE, // '
  CHAR_DOUBLE_QUOTE, // "
  CHAR_SLASH,        // / (special case for comments)
  CHAR_LPAREN,       // (
  CHAR_RPAREN,       // )
  CHAR_LBRACE,       // {
  CHAR_RBRACE,       // }
  CHAR_LBRACKET,     // [
  CHAR_RBRACKET,     // ]
  CHAR_SEMICOLON,    // ;
  CHAR_COMMA,        // ,
  CHAR_DOT,          // .
  CHAR_OTHER,        // any other character
  CHAR_EOF           // end of file
} CharType;

// Function Prototypes
CharType get_char_type(char c);
int is_letter(char c);
int is_digit(char c);
int is_operator(char c);
int is_space(char c);
int is_single_quote(char c);
int is_double_quote(char c);

#endif