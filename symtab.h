#ifndef _SYMTAB_H_
#define _SYMTAB_H_

void st_insert( char * name, int lineno, int loc, char * scope, char * typeId, char *typeData, int len );

int st_lookup( char * name, char * scope, char * StatementKind );

void printSymTab();

char* findFunType (char* name, char* scope);


#endif
