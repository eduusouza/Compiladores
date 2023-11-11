#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_BUFFER 100

enum tokens {IF = 1, ELSE, INT, RETURN, VOID, WHILE, WRITE, SOMA, SUB, MULT, DIV, MENOR, MENOR_IGUAL,
            MAIOR, MAIOR_IGUAL, ATRIB, DIF, IGUAL, PONTO_VIRG, VIRG, ABRE_PARENT, FECHA_PARENT, ABRE_COLCH, FECHA_COLCH,
            ABRE_CHAVES, FECHA_CHAVES, NUM, ID};

char simbolos[] = {'+', '-', '*', '/', '<', '>', '=', '!', ';', ',', '(', ')', '[', ']', '{', '}'};

typedef struct{
    char *buffer;
    int index;
    FILE *arquivo;
    int flag;
    int linha;
} tipoBuffer;

typedef struct{
    int type;
    char *lexema;
    int linha;
} Token;

void allocate_buffer(tipoBuffer *);

void deallocate_buffer(tipoBuffer *);

char get_next_char(tipoBuffer *);

int isSymbol(char);

int cType(char);

Token* inputToken(int, char*, int);