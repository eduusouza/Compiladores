#include "globals.h"
#include "util.h"


void printToken( TokenType token, const char* tokenString ){ 
  	switch (token){ 
		case ELSE: printf("Reserved Word: %s\n",tokenString); break;
		case IF: printf("Reserved Word: %s\n",tokenString); break;
		case INT: printf("Reserved Word: %s\n",tokenString); break;
		case RETURN: printf("Reserved Word: %s\n",tokenString); break;
		case VOID: printf("Reserved Word: %s\n",tokenString); break;
		case WHILE: printf("Reserved Word: %s\n",tokenString); break;
		case ADD: printf("+\n"); break;
		case SUB: printf("-\n"); break;
		case MULT: printf("*\n"); break;
		case DIV: printf("/\n"); break;
		case MENOR: printf("<\n"); break;
		case MENORIG: printf("<=\n"); break;
		case MAIOR: printf(">\n"); break; 
		case MAIORIG: printf(">=\n"); break; 
		case COMP: printf("==\n"); break;
		case DIF: printf("!=\n"); break;
		case IGUAL: printf("Symbol: =\n"); break;
		case SEMI: printf(";\n"); break;
		case VIRG: printf(",\n"); break;
		case ESQPARENT: printf("(\n"); break;
		case DIRPARENT: printf(")\n"); break;
		case ESQCOL: printf("[\n"); break;
		case DIRCOL: printf("]\n"); break;
		case ESQCHAV: printf("{\n"); break;
		case DIRCHAV: printf("}\n"); break;	
		case NUM: printf("Number: %s\n",tokenString); break;
		case ID: printf("ID: %s\n",tokenString); break;
		case FIM: printf("EOF\n"); break;
		case ERROR: printf("ERRO LÉXICO: \"%s\" LINHA: %d\n",tokenString, lineno); Error = TRUE; break;
		default: printf("Token Desconhecido: %d\n",token);
	}
}

TreeNode * newStmtNode(StmtKind kind){ 
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  	int i;

  	if (t==NULL){
    		printf("Out of memory error at line %d\n",lineno);
    }
  	else {
		for (i=0;i<MAXCHILDREN;i++){
	    	t->child[i] = NULL;
		}	    	 
	    t->sibling = NULL;
	    t->nodekind = Declaracao_NodeK;
	    t->kind.stmt = kind;
	    t->lineno = lineno;
  	}	
  	return t;
}

TreeNode * newExpNode(ExpKind kind){ 
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  	int i;

  	if (t==NULL){
    	printf("Out of memory error at line %d\n",lineno);
  	}
  	else {
    	for (i=0;i<MAXCHILDREN;i++) {
    		t->child[i] = NULL;
    	}
		t->sibling = NULL;
		t->nodekind = EXP_NodeK;
		t->kind.exp = kind;
		t->lineno = lineno;
		t->type = Void_ExpT;
  	}
  	return t;
}

char * copyString(char * s){
	int n;
  	char * t;
	if (s==NULL) return NULL;
	n = strlen(s)+1;
	t = malloc(n);
	if (t==NULL)
		printf("Out of memory error at line %d\n",lineno);
	else strcpy(t,s);
	return t;
}

static int indentno = 0;

#define INDENT indentno+=2
#define UNINDENT indentno-=2

static void printSpaces(void){
	int i;
  	for (i=0;i<indentno;i++)
    	printf(" ");
}

void printTree( TreeNode * tree ){ 
	int i;
  	INDENT;
  	while (tree != NULL) {
    	printSpaces();
    	if (tree->nodekind == Declaracao_NodeK){ 
			switch (tree->kind.stmt) {
				case If_StmtK:
					printf("If\n");
					break;

				case Igual_StmtK:
					printf("Atribuicao\n");
					break;

				case While_StmtK:
					printf("While\n");
					break;

				case Variavel_StmtK:
					printf("Variavel %s\n", tree->attr.name);
					break;

				case Vetor_StmtK:
					printf("Vetor %s\n", tree->attr.name);
					break;

				case Parametro_StmtK:
					printf("Parametro %s\n", tree->attr.name);
					break;

				case Funcao_StmtK:
					printf("Funcao %s\n", tree->attr.name);
					break;

				case Call_StmtK:
					printf("Chamada da funcao %s\n", tree->attr.name);
					break; 

				case Return_StmtK:
					printf("Return\n");
					break;

				default:
					printf("Unknown ExpNode kind\n");
					break;
			}
		} else if (tree->nodekind == EXP_NodeK) {
    		switch (tree->kind.exp) {
				case Operacao_ExpK:
					printf("Operacao: ");
					printToken(tree->attr.op,"\0");
					break;
				case Constante_ExpK:
					printf("Constante: %d\n",tree->attr.val);
					break;
				case ID_ExpK:
					printf("Id: %s\n",tree->attr.name);
					break;
				case Vetor_ExpK:
					printf("Vetor: %s\n",tree->attr.name);
					break;
				case Tipo_ExpK:
					printf("Tipo %s\n",tree->attr.name);
					break;
				default:
					printf("Unknown ExpNode kind\n");
					break;
			}
		} else {
			printf("Unknown node kind\n");
		}
		for (i=0;i<MAXCHILDREN;i++){
			printTree(tree->child[i]);
		}		
		tree = tree->sibling;   
	}
  	UNINDENT;
}
