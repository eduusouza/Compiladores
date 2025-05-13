%{
#define YYPARSER
#include "globals.h"  

#define YYSTYPE TreeNode *

static TreeNode * savedTree;
static int yylex(void);
%}

%token IF ELSE INT RETURN VOID WHILE
%token NUM ID
%token SUM SUB MULT DIV LT LET GT GET EQ NEQ ATTR SEMI COMMA OP CP OSB CSB OCB CCB
%token ERROR ENDFILE

%%

program:                list_declaration {
                            savedTree = $1;
                        };

list_declaration:       list_declaration declaration {
                            YYSTYPE t = $1;
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $2;
                                $$ = $1;
                            } else {
                                $$ = $2;
                            }
                        }
                        | declaration {
                            $$ = $1;
                        };

declaration:            var_declaration {
                            $$ = $1;
                        }
                        | fun_declaration {
                            $$ = $1;
                        }
                        | error SEMI {
                            yyerrok;
                        };

var_declaration:        INT ident SEMI {
                            $$ = newExpNode(typeK);
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->nodekind = statementK;
                            $2->kind.stmt = variableK;
                            $2->type = integerK;
                        }
                        | INT ident OSB num CSB SEMI {
                            $$ = newExpNode(typeK);
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->nodekind = statementK;
                            $2->kind.stmt = vectorStmtK;
                            $2->type = integerK;
                            $2->attr.len = $4->attr.val;
                        };

fun_declaration:        INT ident OP params CP compound_decl {
                            $$ = newExpNode(typeK);
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->child[0] = $4;
                            $2->child[1] = $6;
                            $2->nodekind = statementK;
                            $2->kind.stmt = functionK;
                            $2->type = integerK;
                            $4->type = integerK;
                            aggScope($2->child[0], $2->attr.name);
                            aggScope($2->child[1], $2->attr.name);
                        }
                        | VOID ident OP params CP compound_decl {
                            $$ = newExpNode(typeK);
                            $$->type = voidK;
                            $$->attr.name = "void";
                            $$->child[0] = $2;
                            $2->child[0] = $4;
                            $2->child[1] = $6;
                            $2->nodekind = statementK;
                            $2->kind.stmt = functionK;
                            aggScope($2->child[0], $2->attr.name);
                            aggScope($2->child[1], $2->attr.name);
                        };

params:                 param_list {
                            $$ = $1;
                        }
                        | VOID {
                            $$ = newExpNode(typeK);
                            $$->attr.name = "void";
                        };

param_list:             param_list COMMA param {
                            YYSTYPE t = $1;
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $3;
                                $$ = $1;
                            } else {
                                $$ = $3;
                            }
                        }
                        | param {
                            $$ = $1;
                        };

param:                  INT ident {
                            $$ = newExpNode(typeK);
                            $2->nodekind = statementK;
                            $2->kind.stmt = variableK;
                            $$->type = integerK;
                            $2->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                        }
                        | INT ident OSB CSB {
                            $$ = newExpNode(typeK);
                            $2->nodekind = statementK;
                            $2->kind.stmt = vectorStmtK;
                            $$->type = integerK;
                            $$->attr.name = "integer";
                            $$->child[0] = $2;
                            $2->type = integerK;
                        };

compound_decl:          OCB local_declarations statement_list CCB {
                            YYSTYPE t = $2;
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $3;
                                $$ = $2;
                            } else {
                                $$ = $3;
                            }
                        }
                        | OCB local_declarations CCB {
                            $$ = $2;
                        }
                        | OCB statement_list CCB {
                            $$ = $2;
                        }
                        | OCB CCB {

                        };

local_declarations:     local_declarations var_declaration {
                            YYSTYPE t = $1;
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $2;
                                $$ = $1;
                            } else {
                                $$ = $2;
                            }
                        }
                        | var_declaration {
                            $$ = $1;
                        };

statement_list:         statement_list statement {
                            YYSTYPE t = $1;
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $2;
                                $$ = $1;
                            } else {
                                $$ = $2;
                            }
                        }
                        | statement {
                            $$ = $1;
                        };

statement:              expression_decl {
                            $$ = $1;
                        }
                        | compound_decl {
                            $$ = $1;
                        }
                        | selection_decl {
                            $$ = $1;
                        }
                        | iterator_decl {
                            $$ = $1;
                        }
                        | return_decl {
                            $$ = $1;
                        }

expression_decl:        expression SEMI {
                            $$ = $1;
                        }
                        | SEMI {

                        }
                        | error SEMI {
                            yyerrok;
                        };

selection_decl:         IF OP expression CP statement {
                            $$ = newStmtNode(ifK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                        }
                        | IF OP expression CP statement ELSE statement {
                            $$ = newStmtNode(ifK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                            $$->child[2] = $7;
                        };

iterator_decl:          WHILE OP expression CP statement {
                            $$ = newStmtNode(whileK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                        };

return_decl:            RETURN  SEMI {
                            $$ = newStmtNode(returnK);
                            $$->type = voidK;
                        }
                        | RETURN expression SEMI{
                            $$ = newStmtNode(returnK);
                            $$->child[0] = $2;
                        };

expression:             var ATTR expression {
                            $$ = newStmtNode(assignK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->type = integerK;
                        }
                        | simple_expression {
                            $$ = $1;
                        };

var:                    ident {
                            $$ = $1;
                            $$->type = integerK;
                        }
                        | ident OSB expression CSB {
                            $$ = $1;
                            $$->child[0] = $3;
                            $$->kind.exp = vectorK;
                            $$->type = integerK;
                        };

simple_expression:      sum_expression relational sum_expression {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | sum_expression {
                            $$ = $1;
                            $$->type = integerK;
                        };

relational:             EQ {
                            $$ = newExpNode(operationK);
                            $$->attr.op = EQ;
                            $$->type = booleanK;
                        }
                        | NEQ {
                            $$ = newExpNode(operationK);
                            $$->attr.op = NEQ;
                            $$->type = booleanK;
                        }
                        | LT {
                            $$ = newExpNode(operationK);
                            $$->attr.op = LT;
                            $$->type = booleanK;
                        }
                        | LET {
                            $$ = newExpNode(operationK);
                            $$->attr.op = LET;
                            $$->type = booleanK;
                        }
                        | GT {
                            $$ = newExpNode(operationK);
                            $$->attr.op = GT;
                            $$->type = booleanK;
                        }
                        | GET {
                            $$ = newExpNode(operationK);
                            $$->attr.op = GET;
                            $$->type = booleanK;
                        };

sum_expression:         sum_expression sum term {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | term {
                            $$ = $1;
                        };

sum:                    SUM {
                            $$ = newExpNode(operationK);
                            $$->attr.op = SUM;
                        }
                        | SUB {
                            $$ = newExpNode(operationK);
                            $$->attr.op = SUB;
                        };

term:                   term mult factor {
                            $$ = $2;
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                        }
                        | factor {
                            $$ = $1;
                        };

mult:                   MULT {
                            $$ = newExpNode(operationK);
                            $$->attr.op = MULT;
                        }
                        | DIV {
                            $$ = newExpNode(operationK);
                            $$->attr.op = DIV;
                        };

factor:                 OP expression CP {
                            $$ = $2;
                        }
                        | var {
                            $$ = $1;
                        }
                        | activation {
                            $$ = $1;
                        }
                        | num {
                            $$ = $1;
                        };

activation:             ident OP arg_list CP {
                            $$ = $1;
                            $$->child[0] = $3;
                            $$->nodekind = statementK;
                            $$->kind.stmt = callK;
                        }
                        | ident OP CP {
                            $$ = $1;
                            $$->nodekind = statementK;
                            $$->kind.stmt = callK;
                        };

arg_list:               arg_list COMMA expression {
                            YYSTYPE t = $1;
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $3;
                                $$ = $1;
                            } else {
                                $$ = $3;
                            }                 
                        }
                        | expression {
                            $$ = $1;
                        };

ident:                  ID {
                            $$ = newExpNode(idK);
                            $$->attr.name = copyString(tokenString);
                        }
                        ;

num:                    NUM {
                            $$ = newExpNode(constantK);
                            $$->attr.val = atoi(tokenString);
                            $$->type = integerK;
                        };

%%

int yyerror(){
    printf("\nERRO SINTATICO: %s, LINHA: %d\n", tokenString, line_number);
    Error = TRUE;
    return 0;
}

static int yylex(void){
    return getToken();
}

TreeNode * parse(void){
    yyparse();
    return savedTree;
}