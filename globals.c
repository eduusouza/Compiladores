#include "globals.h"

int line_number;
FILE* inputFile;
FILE* outputFile;

// Funções para printar o analisador lexico
void printToken(TokenType token, const char* tokenString ){
    switch (token)
    {
        /* reserved words */
        case IF:
            printf("IF ");
            break;
        case ELSE:
            printf("ELSE ");
            break;
        case INT:
            printf("INT ");
            break;
        case RETURN:
            printf("RETURN ");
            break;
        case VOID:
            printf("VOID ");
            break;
        case WHILE:
            printf("WHILE ");
            break;


        /* special symbols */
        case ATTR: 
            printf("ATTR "); // =
            break;
        case LT: 
            printf("LT "); // <
            break;
        case LET: 
            printf("LET "); // <=
            break;
        case GT: 
            printf("GT "); // >
            break;
        case GET: 
            printf("GET "); // >=
            break;
        case EQ: 
            printf("EQ "); // ==
            break;
        case NEQ: 
            printf("NEQ "); // !=
            break;
        case OP: 
            printf("OP "); // (
            break;
        case CP: 
            printf("CP "); // )
            break;
        case OSB: 
            printf("OSB "); // [
            break;
        case CSB: 
            printf("CSB "); // ] 
            break;
        case OCB: 
            printf("OCB "); // {
            break;
        case CCB: 
            printf("CCB "); // } 
            break;
        case SEMI: 
            printf("SEMI "); // ;
            break;
        case COMMA: 
            printf("COMMA "); // , 
            break;

        /* arithmetic operators */
        case SUM: 
            printf("SUM "); // +
            break;
        case SUB: 
            printf("SUB "); // -
            break;
        case MULT: 
            printf("MULT "); // *
            break;
        case DIV: 
            printf("DIV "); // /
            break;


        /* multicharacter tokens */
        case NUM:
            printf("NUM ");
            break;
        case ID:
            printf("ID ");
            break;

        case YYEOF:
            printf("EOF\n");
            break;

        case ERROR:
            printf("\n\nERRO LEXICO: %s, LINHA: %d\n", tokenString, line_number);
            Error = TRUE;
            break;
            
        default: /* should never happen */
            printf("Unknown token: %d\n", token);
    }
}

// Funções para criação da arvore sintática
TreeNode *newStmtNode(StatementKind kind){
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL){
        printf("Out of memory error at line %d\n", line_number);
    } else {
        for (i = 0; i < MAXCHILDREN; i ++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = statementK;
            t->kind.stmt = kind;
            t->lineno = line_number;
            t->attr.scope = "global";
        }
    }
    return t;
}

TreeNode *newExpNode(ExpressionKind kind){
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL){
        printf("Out of memory error at line %d\n", line_number);
    } else {
        for (i = 0; i < MAXCHILDREN; i ++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = expressionK;
            t->kind.exp = kind;
            t->lineno = line_number;
            t->attr.scope = "global";
        }
    }
    return t;
}

char *copyString(char *s){
  int n;
  char *t;

  if (s == NULL)
    return NULL;

  n = strlen(s) + 1;
  t = malloc(n);
  
  if (t == NULL)
    printf("Out of memory error at line %d\n", line_number);
  else
    strcpy(t, s);
  return t;
}

void aggScope(TreeNode *t, char *scope){
  int i;
  while (t != NULL){
    for (i = 0; i < MAXCHILDREN; ++i)
    {
      t->attr.scope = scope;
      aggScope(t->child[i], scope);
    }
    t = t->sibling;
  }
}

// Funções para printar a arvore
static int indentno = 0;

#define INDENT indentno += 2
#define UNINDENT indentno -= 2

static void printSpaces(void){
    int i;
    for(i = 0; i < indentno; i++)
        printf(" ");
}

void printTree(TreeNode *tree){
    int i;
    INDENT;
    while(tree != NULL){
        printSpaces();
        if(tree->nodekind == statementK){
            switch (tree->kind.stmt){

            case ifK:
                printf("If\n");
                break;

            case assignK:
                printf("Assing\n");
                break;
            
            case whileK:
                printf("While\n");
                break;
            
            case variableK:
                printf("Variable %s\n", tree->attr.name);
                break;
            
            case vectorStmtK:
                printf("Vector %s\n", tree->attr.name);
                break;
            
            case functionK:
                printf("Function %s\n", tree->attr.name);
                break;
            
            case callK:
                printf("Call to Function %s\n", tree->attr.name);
                break;

            case returnK:
                printf("Return\n");
                break;

            default:
                printf("Unknown ExpNode kind\n");
                break;
            }
        } else if(tree->nodekind == expressionK){
            switch (tree->kind.exp){

            case operationK:
                printf("Operation: ");
                printToken(tree->attr.op, "/0");
                printf("\n");
                break;
            
            case constantK:
                printf("Constant: %d\n", tree->attr.val);
                break;
            
            case idK:
                printf("Id: %s\n", tree->attr.name);
                break;
            
            case vectorK:
                printf("Vector: %s\n", tree->attr.name);
                break;
            
            case vectorIdK:
                printf("Index [%d]\n", tree->attr.val);
                break;
            
            case typeK:
                printf("Type %s\n", tree->attr.name);
                break;
            
            default:
                printf("Unknown ExpNode kind\n");
                break;
            }
        } else {
            printf("Unknown node kind");
        }
        for(i = 0; i < MAXCHILDREN; i++){
            printTree(tree->child[i]);
        }
        tree = tree->sibling;
    }
    UNINDENT;
}