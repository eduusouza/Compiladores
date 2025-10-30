#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER

#include "parse.tab.h"

#define ENDFILE 0

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXRESERVED 8


typedef int TokenType; 

extern FILE* source; 
extern FILE* arquivoIntermediario; 
extern FILE* arquivoAssembly; 
extern FILE *arquivoBinario;

extern int lineno;
extern int isRecursive;

typedef struct{
    char name[20];
    int posicao;
} RECURSIVE;

extern RECURSIVE *recursivas;

typedef enum {
	Declaracao_NodeK, EXP_NodeK
} NodeKind;

typedef enum {
	If_StmtK, While_StmtK, Igual_StmtK, Variavel_StmtK, Vetor_StmtK, Funcao_StmtK, Parametro_StmtK, Call_StmtK, Return_StmtK, Read_StmtK, Write_StmtK
} StmtKind;

typedef enum {
	Operacao_ExpK, Constante_ExpK, ID_ExpK, Vetor_ExpK, Tipo_ExpK
} ExpKind;

typedef enum {
	Void_ExpT, Integer_ExpT, Boolean_ExpT
} ExpType;

#define MAXCHILDREN 3

typedef struct treeNode { 
	struct treeNode * child[MAXCHILDREN];
     	struct treeNode * sibling;
     	int lineno;
     	NodeKind nodekind;
     	
     	union {
     		StmtKind stmt; 
     		ExpKind exp;
     	} kind;
     	
     	struct { 
     		TokenType op;
			int val;
      		int len;
        	char * name; 
			char * escopo;
		} attr;
	
     	ExpType type;
} TreeNode;

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* EchoSource = TRUE causes the source program to
 * be echoed to the listing file with line numbers
 * during parsing
 */
extern int EchoSource;

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to be written
 * to the TM arquivoIntermediario file as arquivoIntermediario is generated
 */
extern int TraceCode;

/* Error = TRUE prevents further passes if an error occurs */
extern int Error; 
#endif
