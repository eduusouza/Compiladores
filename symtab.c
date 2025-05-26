#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "globals.h"

#define SIZE 211

#define SHIFT 4


typedef struct LineListRec{
    int lineno;
    struct LineListRec *next;
} * LineList;


typedef struct BucketListRec{
    char *name;
    LineList lines;
    char *tipo;
    char *tipoExp;
    int memloc; /* memory location for variable */
    char *escopo;
    char *param;
    char *vetor;
    int qtdParametros;

    struct BucketListRec *next;
} * BucketList;


static BucketList hashTable[SIZE];

static int hash(char *key){
    int temp = 0;
    int i = 0;
    while (key[i] != '\0'){
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

static int hash2(char *nome_id, char *escopo){
    int temp = 0, i = 0;
    while (nome_id[i] != '\0'){
        temp = ((temp << SHIFT) + nome_id[i]) % SIZE;
        i++;
    }
    i = 0;
    while (escopo[i] != '\0'){
        temp = ((temp << SHIFT) + escopo[i]) % SIZE;
        i++;
    }
    return temp;
}

BucketList BuscaNaTabelaHash(char *nome, char *escopo){
    int h = hash(nome);
    BucketList no = hashTable[h];
    while ((no != NULL)){
        if ((strcmp(no->escopo, escopo) == 0) && (strcmp(no->name, nome) == 0)){ // nome e escopo iguais ao alvo
            break;
        }
        no = no->next;
    }
    if (no != NULL){
        return no;
    }

    return NULL;
}

int IntVerificaOcorrenciaNoMesmoEscopo(char *nomeDoNo, char *escopoAtualDoNo){
    BucketList no = BuscaNaTabelaHash(nomeDoNo, escopoAtualDoNo);

    if (no == NULL)    {
        return -1;
    } else {
        return 1;
    }
}

int IntVerificaOcorrenciaNoEscopoGlobal(char *name, char *scope){
    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL))    {
        if ((strcmp("Global", scope) == 0) && (strcmp(name, l->name) == 0)){ // nome e escopo iguais ao alvo
            // já existe na tabela com esse nome e esse escopo
            break;
        }
        l = l->next;
    }

    if (l == NULL){
        return -1;
    } else {
        return 1;
    }
}

char *CharVerificaOcorrenciaNoMesmoEscopo(char *nomeDoNo, char *escopoAtualDoNo, char *tipoDeRetorno){
    BucketList no = BuscaNaTabelaHash(nomeDoNo, escopoAtualDoNo);

    if (no == NULL)    {
        return " ";
    } else {
        // A função irá retornar o valor do nó se este existir no mesmo escopo com o tipo de dados correto
        if (strcmp(tipoDeRetorno, "tipoExpressao") == 0){
            return no->tipoExp;
        } else if (strcmp(tipoDeRetorno, "tipoDeclaracao") == 0){
        // A função irá retornar o valor do nó se a variável existir no mesmo escopo com o tipo de declaração correto
            return no->tipo;
        } else if (strcmp(tipoDeRetorno, "tipoParametro") == 0){
        // A função irá retornar o valor do nó se este existir no mesmo escopo com o tipo do parametros correto
            return no->param;
        }
        else if (strcmp(tipoDeRetorno, "tipoVetor") == 0){
        // A função irá retornar o valor do nó se este existir no mesmo escopo com o tipo do vetor correto
            return no->vetor;
        } else {
            return " ";
        }
    }
}

/*Função que retorna a posição da variável ou -1 caso não seja encontrada*/
int procuraPelaString(char *name){
    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0))
        l = l->next;

    if (l == NULL){
        return -1;
    } else {
        return l->memloc;
    }
}

void st_insert(char *name, int lineno, int loc, int tipo, int tipoExp, char *escopo, char *param, char *vetor, int qtdParametros){
    int h = hash(name);
    BucketList l = hashTable[h];

    while ((l != NULL)){
        if (escopo != NULL){
            if ((strcmp(escopo, l->escopo) == 0) && (strcmp(name, l->name) == 0)){ // nome e escopo iguais ao alvo
                // já existe na tabela com esse nome e esse escopo
                break;
            }
        } else {
            if ((strcmp(name, l->name) == 0))
                break;
        }

        l = l->next;
    }

    if (l == NULL){
        l = (BucketList)malloc(sizeof(struct BucketListRec));

        l->name = name;
        l->lines = (LineList)malloc(sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->memloc = loc;
        l->escopo = escopo;
        l->param = param;
        l->vetor = vetor;
        l->qtdParametros = qtdParametros;

        if (tipo == 3){
            l->tipo = "var";
        } else if (tipo == 4){
            l->tipo = "fun";
        }

        if (tipoExp == 0){
            l->tipoExp = "void";
        } else if (tipoExp == 1){
            l->tipoExp = "int";
        } else {
            l->tipoExp = "bool";
        }

        l->lines->next = NULL;
        l->next = hashTable[h];

        hashTable[h] = l;
    } else { /* found in table, so just add line number */
    
        LineList t = l->lines;
        while (t->next != NULL)
            t = t->next;
        t->next = (LineList)malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
    }
}

char **getVariableVector(char *scope, int *lenght){
    int j = 0;
    int i = 0;
    char **vect = (char **)malloc((j + 1) * sizeof(char *));
    for (i; i < SIZE; ++i){
        if (hashTable[i] != NULL){
            BucketList l = hashTable[i];
            while (l != NULL){
                if (strcmp(l->escopo, scope) == 0){
                    if (strcmp(l->vetor, "nao") == 0 || strcmp(l->vetor, ".") == 0){
                        vect = (char **)realloc(vect, (j + 1) * sizeof(char *));
                        vect[j] = l->name;
                        j++;
                        (*lenght)++;
                    }
                }

                l = l->next;
            }
        }
    }
    return vect;
}

int VerificaEquivalenciaParametrosDaFuncao(char *nomeDaFuncao, int qtdArgumentosDaFuncCall){
    BucketList no = BuscaNaTabelaHash(nomeDaFuncao, "Global");

    if (no != NULL && no->qtdParametros == qtdArgumentosDaFuncCall){
        return 1;
    }

    return 0;
}

int busca_indice(char *nome, char *escopo, char *tipo_id){
    int h = hash(nome);
    BucketList no = hashTable[h];
    while ((no != NULL)){
        if ((strcmp(tipo_id, no->tipo) != 0) || (strcmp(no->escopo, escopo) == 0) && (strcmp(no->name, nome) == 0)){ // nome e escopo iguais ao alvo
            // já existe na tabela com esse nome e esse escopo
            break;
        }
        no = no->next;
    }

    if (no != NULL){
        return no->memloc;
    }

    return -1;
}

void imprimeTabela(){
    int i;
    printf("Nome Variavel  Tipo Variavel   Tipo Dado    Nome Escopo    memloc      param      vetor       Line Numbers\n");
    printf("-------------  -------------   ---------    -----------    ------      -----      -----       ------------\n");
    for (i = 0; i < SIZE; ++i){
        if (hashTable[i] != NULL){
            BucketList l = hashTable[i];
            while (l != NULL){
                LineList t = l->lines;
                printf("%-15s ", l->name);
                printf("%-14s  ", l->tipo);
                printf("%-11s  ", l->tipoExp);
                printf("%-12s  ", l->escopo);
                printf("%-12d  ", l->memloc);
                printf("%-10s  ", l->param);
                printf("%-8s  ", l->vetor);
                while(t != NULL){
                    printf("%2d ", t->lineno);
                    t = t->next;
                }
            

                printf("\n");
                l = l->next;
            }
        }
    }
    printf("\n");
}
