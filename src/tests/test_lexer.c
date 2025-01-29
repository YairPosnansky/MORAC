#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "lexer/lexer.h"

void print_token(Token *token)
{
  printf("TOKEN: %-15s  LEXEME: '%-15s'  LINE: %d  COL: %d\n",
         get_token_name(token->type),
         token->lexeme,
         token->line,
         token->column);
}

void test_lexer_output(const char *source, const char *test_name)
{
  printf("\n=== Testing %s ===\n", test_name);
  printf("Source code:\n%s\n", source);
  printf("\nLexical Analysis Output:\n");
  printf("------------------------------------------------------------\n");

  Lexer *lexer = lexer_create(source);
  if (!lexer)
  {
    printf("Failed to create lexer!\n");
    return;
  }

  Token *token;
  while (1)
  {
    token = lexer_next_token(lexer);
    if (!token)
    {
      printf("Failed to get next token!\n");
      break;
    }

    print_token(token);

    if (token->type == TOKEN_EOF || token->type == TOKEN_ERROR)
    {
      free_token(token);
      break;
    }
    free_token(token);
  }

  printf("------------------------------------------------------------\n\n");
  lexer_destroy(lexer);
}

int main()
{
  // Test 1: Basic variable declarations and operations
  const char *test1 =
      "int main() {\n"
      "    int x = 42;\n"
      "    float y = 3.14;\n"
      "    return x;\n"
      "}\n";
  test_lexer_output(test1, "Basic Declarations and Operations");

  // Test 2: Control structures and operators
  const char *test2 =
      "if (x <= 10) {\n"
      "    while (y > 0) {\n"
      "        y -= 1.5;\n"
      "    }\n"
      "}\n";
  test_lexer_output(test2, "Control Structures and Operators");

  // Test 3: Comments and strings
  const char *test3 =
      "/* Multi-line\n"
      "   comment */\n"
      "char *str = \"Hello!\";\n"
      "// Single line comment\n"
      "char c = 'X';\n";
  test_lexer_output(test3, "Comments and Strings");

  // Test 4: Complex expressions
  const char *test4 =
      "int calculate(int a, float b) {\n"
      "    return (a + b) * 2 - (3 / a);\n"
      "}\n";
  test_lexer_output(test4, "Complex Expressions");

  // Test 5: Error cases
  const char *test5 =
      "int test() {\n"
      "    int @invalid = 42;\n"
      "    char *str = \"unterminated;\n"
      "    return 0;\n"
      "}\n";
  test_lexer_output(test5, "Error Cases");

  return 0;
}