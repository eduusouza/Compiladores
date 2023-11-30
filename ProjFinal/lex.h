#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_BUFFER 100
#define TAM_LEXEMA 64
#define TAM_THASH 700

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
    int validacao;
} Token;

typedef struct HNode {
    char key[50];
    int value;
    struct HNode* next;
} HNode;

int hash(char* key);

void insertTHash(HNode *[], char *, int);

int searchTHash(HNode *[], char *);

void allocateBuffer(tipoBuffer *);

void deallocateBuffer(tipoBuffer *);

void allocateToken(Token *);

void deallocateToken(Token *);

char getNextChar(tipoBuffer *);

int cType(char);

Token getNextToken(tipoBuffer *, Token *);

void ungetChar(tipoBuffer *);