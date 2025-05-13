#define _GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YYPARSER

#include "parser.tab.h"

#endif

#define TRUE 1
#define FALSE 0
#define MAXRESERVED 6

#define MAXCHILDREN 3

#define MAXTOKENLEN 32

extern int line_number;
extern FILE* inputFile;
extern FILE* outputFile;
extern char tokenString[MAXTOKENLEN+1];
extern FILE* arquivoIntermediario;

typedef int TokenType;

typedef enum {
    statementK, expressionK
} NodeKind;

typedef enum {
    ifK, whileK, assignK, variableK, functionK, callK, returnK, numberK, vectorStmtK
} StatementKind;

typedef enum {
    operationK, constantK, idK, vectorK, vectorIdK, typeK
} ExpressionKind;

typedef enum {
    voidK, integerK, booleanK
} ExpressionType;

typedef struct treeNode{
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;

    int lineno;
    NodeKind nodekind;

    union {
        StatementKind stmt;
        ExpressionKind exp;
    } kind;

    struct {
        TokenType op;
        int val;
        int len;
        char* name;
        char* scope;
    } attr;

    ExpressionType type;

} TreeNode;

extern int TraceScan;
extern int TraceAnalyze;
extern int Error;

void printToken(TokenType, const char*);

TokenType getToken(void);

TreeNode *newStmtNode(StatementKind);
TreeNode *newExpNode(ExpressionKind);

char *copyString(char *);
void aggScope(TreeNode*, char*);

#ifndef _PARSE_H_
#define _PARSE_H_

TreeNode * parse(void);
#endif

void printTree(TreeNode *);
