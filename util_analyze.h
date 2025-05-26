#ifndef _UTILANALYZE_H_
#define _UTILANALYZE_H_
#include <stdbool.h>

void nullProc(TreeNode * );
void erroTipo(TreeNode * , char * );
void DeclaracaoDeErro(TreeNode * , char * );
void VerificaExistenciaDaFuncaoMain();
bool existInGlobalEscope(TreeNode * no);
bool nameDontExistInHashTable(TreeNode * no);

#endif