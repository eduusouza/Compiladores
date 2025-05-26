#ifndef _SYMTAB_H_
#define _SYMTAB_H_

void st_insert(char *name, int lineno, int loc, int tipo, int tipoExp, char *escopo, char *param, char *vetor, int qtdParametros);


int procuraPelaString ( char * name );

int VerificaOcorrenciaEmOutroEscopo(char *name, char *scope);

int IntVerificaOcorrenciaNoMesmoEscopo(char *nomeDoNo, char *escopoAtualDoNo);

char *CharVerificaOcorrenciaNoMesmoEscopo(char *nomeDoNo, char *escopoAtualDoNo, char *tipoDeRetorno);

char ** getVariableVector (char *scope, int *lenght);

int busca_indice(char *name, char *scope, char *id_type);

void imprimeTabela(void);

int VerificaEquivalenciaParametrosDaFuncao( char * nomeDaFuncao, int qtdArgumentosDaFuncCall );

#endif