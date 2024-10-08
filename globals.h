#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_TOKEN_LEN 50

enum TOKENS {INT, IF, ELSE, RETURN, VOID, WHILE, ASSIGN, EQ, LESS_THAN, GREATER_THAN, LESS_THAN_EQ, GREATER_THAN_EQ, NOT_EQ,
    OPEN_BRACKET, CLOSE_BRACKET, OPEN_KEYS, CLOSE_KEYS, SUM, SUBTRACT, MULTIPLY, DIVIDE, OPEN_PARENTHESES, CLOSE_PARENTHESES,
    COMMA, SEMICOLON, NUM, ID, ERROR};

int yyline = 1;