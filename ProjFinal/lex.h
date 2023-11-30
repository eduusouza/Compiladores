#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_BUFFER 100
#define TAM_LEXEMA 64

enum Tokens {IF, ELSE, INT, RETURN, VOID, WHILE, WRITE, SOMA, SUB, MULT, DIV, MENOR, MENOR_IGUAL,
            MAIOR, MAIOR_IGUAL, ATRIB, DIF, IGUAL, PONTO_VIRG, VIRG, ABRE_PARENT, FECHA_PARENT, ABRE_COLCH, FECHA_COLCH,
            ABRE_CHAVES, FECHA_CHAVES, NUM, ID};


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
    int endOfFile;
} Token;

void allocateBuffer(tipoBuffer *);

void deallocateBuffer(tipoBuffer *);

void allocateToken(Token *);

void deallocateToken(Token *);

char getNextChar(tipoBuffer *);

int isSymbol(char);

int cType(char);

Token getNextToken(tipoBuffer *, Token *);

void ungetChar(tipoBuffer *);