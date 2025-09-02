%{

#define YYPARSER /* distinguishes Yacc output from other arquivoIntermediario files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

void yyerror(char* message);
static int yylex(void);
TreeNode * parse(void);

%}

%token ELSE IF INT RETURN VOID WHILE
%token ID NUM 
%token ADD SUB MULT DIV
%token MENOR MENORIG MAIOR MAIORIG COMP IGUAL DIF
%token SEMI VIRG ESQPARENT DIRPARENT ESQCOL DIRCOL ESQCHAV DIRCHAV
%token ERROR FIM

%% /* Grammar for TINY */


programa: 
	declaracao_lista {
		savedTree = $1;
	};
	
declaracao_lista:
	declaracao_lista declaracao_lista { 
		YYSTYPE t = $1;
           	if (t != NULL){
           		while (t->sibling != NULL) {
           			t = t->sibling;
           		}
             		t->sibling = $2;
             		$$ = $1; 
             	}
             	else { 
             		$$ = $2;
             	}
         }
         | declaracao { 
         	$$ = $1; 
         };
         
declaracao:
	var_declaracao {
		$$ = $1;
	} 
	| fun_declaracao {
		$$ = $1;
	};

var_declaracao:
	tipo_especificador ident SEMI {
		$$ = $1;
		$$->child[0] = $2;
		$2->nodekind = Declaracao_NodeK;
		$2->kind.stmt = Variavel_StmtK;
		$2->type = $1->type;
	} 
	| tipo_especificador ident ESQCOL num DIRCOL SEMI {
		$$ = $1;
		$$->child[0] = $2;
		$2->nodekind = Declaracao_NodeK;
		$2->kind.stmt = Vetor_StmtK;
		$2->attr.len = $4->attr.val;
		$2->type = $1->type;
	};

tipo_especificador:
	INT {
		$$ = newExpNode(Tipo_ExpK);
		$$->type = Integer_ExpT;
		$$->attr.name = "Integer";
	}
	| VOID {
		$$ = newExpNode(Tipo_ExpK);
		$$->type = Void_ExpT;
		$$->attr.name = "Void";
	};
	
fun_declaracao:
	tipo_especificador ident ESQPARENT params DIRPARENT composto_decl {
		$$ = $1;
		$$->child[0] = $2;
		$2->child[0] = $4;
		$2->child[1] = $6;
		$2->nodekind = Declaracao_NodeK;
		$2->kind.stmt = Funcao_StmtK;
		$2->type = $1->type;
	};

params:
	param_lista{
		$$ = $1;
	} 
	| VOID {
		//Região vazia
	};
            
param_lista:
	param_lista VIRG param {
		YYSTYPE t = $1;
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = $3;
			$$ = $1;
		}
		else {
			$$ = $1; //&3
		}	
	} 
	| param {
		$$ = $1;
	};

param:
	tipo_especificador ident {
		$$ = $1;
		$$->child[0] = $2;
		$2->nodekind = Declaracao_NodeK;
		$2->kind.stmt = Parametro_StmtK;
		$2->type = $1->type;
	} 
	| tipo_especificador ident ESQCOL DIRCOL {
		$$ = $1;
		$$->child[0] = $2;
		$2->kind.exp = Vetor_ExpK;
		$2->nodekind = Declaracao_NodeK;
		$2->kind.stmt = Parametro_StmtK;
		$2->type = $1->type;
	};
	
composto_decl:
	ESQCHAV local_declaracoes statement_lista DIRCHAV {
		YYSTYPE t = $2;
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = $3;
			$$ = $2;
		}
		else {
			$$ = $3;
		}
	}
	| ESQCHAV local_declaracoes DIRCHAV {
		$$ = $2;
	}
	| ESQCHAV statement_lista DIRCHAV {
		$$ = $2;
	}
	| ESQCHAV DIRCHAV {
	    	//Região vazia
	};
      
local_declaracoes:
	local_declaracoes var_declaracao {
		YYSTYPE t = $1;
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = $2;
			$$ = $1;
		}
		else {
			$$ = $2;
		}		
	} 
	| var_declaracao {
		$$ = $1;
	};
            
statement_lista:
    	statement_lista statement {
    		YYSTYPE t = $1;
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = $2;
			$$ = $1;
		}
		else {
			$$ = $2;
		}
    	} 
    	| statement {
		$$ = $1;
	}; 
            
statement:
    	expressao_decl {
    		$$ = $1;
    	} 
    	| composto_decl {
    		$$ = $1;
    	} 
    	| selecao_decl {
    		$$ = $1;
    	} 
    	| iteracao_decl {
    		$$ = $1;
    	}
    	| retorno_decl {
    		$$ = $1;
    	};

expressao_decl:
    	expressao SEMI {
    		$$ = $1;
    	} 
    	| SEMI {
    		//Região vazia
    	};
    
selecao_decl:
    	IF ESQPARENT expressao DIRPARENT statement {
    		$$ = newStmtNode(If_StmtK);
    		$$->child[0] = $3;
    		$$->child[1] = $5;
    	} 
    	| IF ESQPARENT expressao DIRPARENT statement ELSE statement {
    		$$ = newStmtNode(If_StmtK);
    		$$->child[0] = $3;
    		$$->child[1] = $5;
    		$$->child[2] = $7;
    	};

iteracao_decl:
    	WHILE ESQPARENT expressao DIRPARENT statement {
    		$$ = newStmtNode(While_StmtK);
    		$$->child[0] = $3;
    		$$->child[1] = $5;
    	};
            
retorno_decl:
    	RETURN SEMI {
    		$$ = newStmtNode(Return_StmtK);
    	} 
    	| RETURN expressao SEMI {
    		$$ = newStmtNode(Return_StmtK);
    		$$->child[0] = $2;
    	};
              
expressao:
    	var IGUAL expressao {
    		$$ = newStmtNode(Igual_StmtK);
    		$$->child[0] = $1;
    		$$->child[1] = $3;
    	} 
    	| simples_expressao {
    		$$ = $1;
    	};

var:
	ident {
		$$ = $1;
	} 
	| ident ESQCOL expressao DIRCOL {
		$$ = $1;
		$$->child[0] = $3;
		$$->kind.exp = Vetor_ExpK;
	};
            
simples_expressao:
	soma_expressao relacional soma_expressao {
		$$ = $2;
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	| soma_expressao {
		$$ = $1;
	};
            
relacional:
	MENORIG {
		$$ = newExpNode(Operacao_ExpK);
		$$->attr.op = MENORIG;
	}
	| MAIOR {
		$$ = newExpNode(Operacao_ExpK);
		$$->attr.op = MAIOR;
	} 
	| MENOR {
		$$ = newExpNode(Operacao_ExpK);
		$$->attr.op = MENOR;
	} 
	| MAIORIG {
		$$ = newExpNode(Operacao_ExpK);
		$$->attr.op = MAIORIG;
	} 
	| COMP {
		$$ = newExpNode(Operacao_ExpK);
		$$->attr.op = COMP;
	} 
	| DIF {
		$$ = newExpNode(Operacao_ExpK);
		$$->attr.op = DIF;
	};
            
soma_expressao:
    	soma_expressao soma termo {
    		$$ = $2;
    		$$->child[0] = $1;
    		$$->child[1] = $3;
    	} 
    	| termo {
    		$$ = $1;
    	};

soma:
    	ADD {
    		$$ = newExpNode(Operacao_ExpK);
    		$$->attr.op = ADD;
    	} 
    	| SUB {
    		$$ = newExpNode(Operacao_ExpK);
    		$$->attr.op = SUB;
    	}; 
            
termo:
    	termo mult fator {
    		$$ = $2;
    		$$->child[0] = $1;
    		$$->child[1] = $3;
    	}
    	| fator {
    		$$ = $1;
    	};
            
mult:
	MULT {
    		$$ = newExpNode(Operacao_ExpK);
    		$$->attr.op = MULT;
    	} 
    	| DIV {
    		$$ = newExpNode(Operacao_ExpK);
    		$$->attr.op = DIV;
    	};
    	
fator: 
	ESQPARENT expressao DIRPARENT {
		$$ = $2;
	} 
	| var {
		$$ = $1;
	} 
	| ativacao {
		$$ = $1;
	} 
	| num {
		$$ = $1;
	};
	
ativacao:
    	ident ESQPARENT arg_lista DIRPARENT {
	    	$$ = $1;
	    	$$->child[0] = $3;
	    	$$->nodekind = Declaracao_NodeK;
	    	$$->kind.stmt = Call_StmtK;
    	}
	| ident ESQPARENT DIRPARENT {
		$$ = $1;
		$$->nodekind = Declaracao_NodeK;
		$$->kind.stmt = Call_StmtK;
	};
	
arg_lista: 
	arg_lista VIRG expressao {
	 	YYSTYPE t = $1;
		if (t != NULL) {
			while (t->sibling != NULL){
				t = t->sibling;
			}
			t->sibling = $3;
			$$ = $1;
		}
		else 
			$$ = $3;	
	} 
	| expressao {
		$$ = $1;
	};
	
ident:
	ID {
		$$ = newExpNode(ID_ExpK);
		$$->attr.name = copyString(tokenString);
	};

num:
	NUM {
		$$ = newExpNode(Constante_ExpK);
		$$->attr.val = atoi(tokenString);
	};


%%

void yyerror(char* message) {
    if(yychar != FIM && !Error){	
	    	printf("ERRO SINTÁTICO: \"%s\"  LINHA: %d\n", tokenString,lineno);
	    	Error = TRUE;
	}
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void) { 
	return getToken(); 
}

TreeNode * parse(void) {
	yyparse();
  	return savedTree;
}

