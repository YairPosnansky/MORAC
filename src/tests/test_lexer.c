#include "lexer/lexer.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void print_token(Token *token) {
  printf("\033[0;35mTOKEN:\033[0;32m %-15s  \033[0;36mLEXEME: "
         "\033[0;32m'%-15s'  \033[0;34mLINE\033[0m: "
         "%d  \033[0;34mCOL\033[0m: %d\n",
         get_token_name(token->type), token->lexeme, token->line,
         token->column);
}

void test_lexer_output(const char *source, const char *test_name) {
  printf("\n=== Testing %s ===\n", test_name);
  printf("\033[0;34mSource code:\033[0m\n%s\n", source);
  printf("\n\033[0;33mLexical Analysis Output:\033[0m\n");
  printf("------------------------------------------------------------\n");

  Lexer *lexer = lexer_create(source);
  if (!lexer) {
    printf("Failed to create lexer!\n");
    return;
  }

  Token *token;
  while (1) {
    token = lexer_next_token(lexer);
    if (!token) {
      printf("Failed to get next token!\n");
      break;
    }

    print_token(token);

    if (token->type == TOKEN_EOF || token->type == TOKEN_ERROR) {
      free_token(token);
      break;
    }
    free_token(token);
  }

  printf("------------------------------------------------------------"
         "\n\n");
  lexer_destroy(lexer);
}

int main() {
  // Test 1
  const char *test1 = "int main() {\n"
                      "    int x = 42;\n"
                      "    float y = 3.14;\n"
                      "    return x;\n"
                      "}\n";
  test_lexer_output(test1, "Basic Declarations and Operations");

  // Test 2
  const char *test2 = "if (x <= 10) {\n"
                      "    while (y > 0) {\n"
                      "        y -= 1.5;\n"
                      "    }\n"
                      "}\n";
  test_lexer_output(test2, "Control Structures and Operators");

  // Test 3
  const char *test3 = "hello char c = 'X';\n"
                      "// hiiiiii :)\n"
                      "char *str = \"hello there\"\n";
  test_lexer_output(test3, "Comments and Strings");

  // Test 4
  const char *test4 = "int calculate(int a, float b) {\n"
                      "    return (a + b) * 2 - (3 / a);\n"
                      "}\n";
  test_lexer_output(test4, "Complex Expressions");

  // Test 5
  const char *test5 = "int test() {\n"
                      "    int valid = 42;\n"
                      "    char *str = \"unterminated;\n"
                      "    return 0;\n"
                      "}\n";
  test_lexer_output(test5, "Error Cases");

  // Test 6
  const char *test6 = "int test() {\n"
                      "    int valid = 42;\n"
                      "    return 0;\n"
                      "}\n"
                      "test()\n";
  test_lexer_output(test6, "Function Identifiers");
  return 0;
}