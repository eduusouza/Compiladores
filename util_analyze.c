#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "globals.h"
#include "symtab.h"

void nullProc(TreeNode * no) { 
	if (no == NULL) return;
    else return;
}

void erroTipo(TreeNode * no, char * msg) { 
  	printf("ERRO SEMÂNTICO: %s LINHA: %d -> %s\n", no->attr.name, no->lineno, msg);
  	Error = TRUE;
}

void DeclaracaoDeErro(TreeNode * no, char * msg) { 
  	printf("ERRO SEMÂNTICO: %s LINHA: %d -> %s\n", no->attr.name, no->lineno, msg);
  	Error = TRUE;
}

void VerificaExistenciaDaFuncaoMain(){
  if (IntVerificaOcorrenciaNoMesmoEscopo("main", "Global") == -1){
    printf("Função main não declarada.\n\n");
    Error = TRUE;
  }
}

bool existInGlobalEscope(TreeNode * no){
	if(IntVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global") == 1)
		return true;

	return false;
}

bool nameDontExistInHashTable(TreeNode * no){
	if(procuraPelaString(no->attr.name) == -1){
		return true;
	}

	return false;
}