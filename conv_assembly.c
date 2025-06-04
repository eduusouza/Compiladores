#include "globals.h"
#include "symtab.h"
#include <string.h>
#include "cgen.h"
#include "conv_assembly.h"

int *posicaoRetornoLabel;
int contaQtdParametros = 0;
int argumentoAtual = 0;
int contaQtdArgumento = 0;
static int linhaAtual = 1;
static int qtdFunc = 0;

char function[40];

void nome_instrucao(char *read);

void labels(){
    char aux[10];
    int j;

    for (int i = 0; i < linhaAtual; i++){
        if (strcmp(instrucao[i].instruc, "addi") == 0){
            if (strcmp(instrucao[i].regD, "PC") == 0){
                j = i + 1;
                while (strcmp(instrucao[j].instruc, "jal") != 0){
                    j++;
                }
                printf("j: %d \n", j);
                char aux2[10];

                sprintf(aux2, "%d", j);
                strcpy(instrucao[i].regD, aux2);
            }

        } else if (strcmp(instrucao[i].instruc, "jump") == 0){
            if (instrucao[i].reg1[0] == 'L'){
                j = 1;

                while (instrucao[i].reg1[j] != '\0'){
                    aux[j - 1] = instrucao[i].reg1[j];
                    j++;
                }

                aux[j] = '\0';
                char aux2[10];
                sprintf(aux2, "%d", posicaoRetornoLabel[atoi(aux)]);
                strcpy(instrucao[i].reg1, aux2);
            }

        } else if (strcmp(instrucao[i].instruc, "jmain") == 0){
            char aux[5];
            sprintf(aux, "%d", linhaMain);
            strcpy(instrucao[i].reg1, aux);

        } else if (strcmp(instrucao[i].instruc, "bne") == 0 ||
        strcmp(instrucao[i].instruc, "beq") == 0 ||
        strcmp(instrucao[i].instruc, "blt") == 0 ||
        strcmp(instrucao[i].instruc, "bgt") == 0 ||
        strcmp(instrucao[i].instruc, "ble") == 0 ||
        strcmp(instrucao[i].instruc, "bge") == 0){

            j = 1;
            while (instrucao[i].regD[j] != '\0'){
                aux[j - 1] = instrucao[i].regD[j];
                j++;
            }

            aux[j] = '\0';
            char aux2[10];
            sprintf(aux2, "%d", posicaoRetornoLabel[atoi(aux)]);
            strcpy(instrucao[i].regD, aux2);
        }
    }
}

int parametro(char *linha, int indice){
    int j = 0, i;

    for (i = indice; i < 40 && linha[i] != ','; i++){
        registrador[j] = linha[i];
        j++;
    }
    registrador[j] = '\0';
    return i + 1;
}

void ultimo_parametro(char *linha, int indice){
    int j = 0, i;
    for (i = indice; i < 40 && linha[i] != ')'; i++){
        registrador[j] = linha[i];
        j++;
    }
    registrador[j] = '\0';
}

int buscaValorEnderecoRegistrador(char *regAux){ // retorna o número do registrador no processador
    if (strcmp(regAux, "$zero") == 0 || strcmp(registrador, "-") == 0 || strcmp(registrador, "0") == 0){
        return $zero;

    } else if (strcmp(regAux, "$at") == 0){
        return $at;

    } else if (strcmp(regAux, "$v0") == 0){
        return $v0;

    } else if (strcmp(regAux, "$v1") == 0){
        return $v1;

    } else if (strcmp(regAux, "$a0") == 0){
        return $a0;

    } else if (strcmp(regAux, "$a1") == 0){
        return $a1;

    } else if (strcmp(regAux, "$a2") == 0){
        return $a2;

    } else if (strcmp(regAux, "$a3") == 0){
        return $a3;

    } else if (strcmp(regAux, "$t0") == 0){
        return $t0;

    } else if (strcmp(regAux, "$t1") == 0){
        return $t1;

    } else if (strcmp(regAux, "$t2") == 0){
        return $t2;

    } else if (strcmp(regAux, "$t3") == 0){
        return $t3;

    } else if (strcmp(regAux, "$t4") == 0){
        return $t4;

    } else if (strcmp(regAux, "$t5") == 0){
        return $t5;

    } else if (strcmp(regAux, "$t6") == 0){
        return $t6;

    } else if (strcmp(regAux, "$t7") == 0){
        return $t7;

    } else if (strcmp(regAux, "$t8") == 0){
        return $t8;

    } else if (strcmp(regAux, "$t9") == 0){
        return $t9;

    } else if (strcmp(regAux, "$t10") == 0){
        return $t10;

    } else if (strcmp(regAux, "$t11") == 0){
        return $t11;

    } else if (strcmp(regAux, "$t12") == 0){
        return $t12;

    } else if (strcmp(regAux, "$t13") == 0){
        return $t13;

    } else if (strcmp(regAux, "$t14") == 0){
        return $t14;

    } else if (strcmp(regAux, "$t15") == 0){
        return $t15;

    } else if (strcmp(regAux, "$t16") == 0){
        return $t16;

    } else if (strcmp(regAux, "$t17") == 0){
        return $t17;

    } else if (strcmp(regAux, "$t18") == 0){
        return $t18;

    } else if (strcmp(regAux, "$t19") == 0){
        return $t19;

    } else if (strcmp(regAux, "$sp") == 0){
        return $sp;

    } else if (strcmp(regAux, "$hi") == 0){
        return $hi;

    } else if (strcmp(regAux, "$lo") == 0){
        return $lo;

    } else if (strcmp(regAux, "$ra") == 0){
        return $ra;
    }
}

void addi(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "addi");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    indice = parametro(linha, indice);

    strcpy(instrucao[linhaAtual].regD, registrador);
    strcpy(instrucao[linhaAtual].reg1, "$0,");
}

void jump(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "jump");

    indice = parametro(linha, indice);

    strcpy(instrucao[linhaAtual].reg1, registrador);
    strcpy(instrucao[linhaAtual].reg2, "");
    strcpy(instrucao[linhaAtual].regD, "");
}

void label(char *linha, int indice){
    int j = 0, i;

    for (i = indice + 1; i < 40 && linha[i] != ','; i++){
        registrador[j] = linha[i];
        j++;
    }
    registrador[j] = '\0';

    posicaoRetornoLabel[atoi(registrador)] = linhaAtual;
    indice = parametro(linha, indice);
    strcpy(instrucao[linhaAtual].label, registrador);
    linhaAtual--;
}

void funcao(char *linha, int indice){
    // armazeno qual é a label relacionada à essa funcao

    indice = parametro(linha, indice);
    indice = parametro(linha, indice);

    sprintf(function, "%s", registrador);
    if (strcmp(function, "main") == 0)    {
        linhaMain = linhaAtual;
    }

    // aloco mais uma posicao pro vetor
    posicaoLabel = (LABEL *)realloc(posicaoLabel, (qtdFunc + 1) * sizeof(LABEL));

    // coloco o nome da funcao no vetor
    strcpy(posicaoLabel[qtdFunc].name, registrador);
    posicaoLabel[qtdFunc].posicao = linhaAtual;

    qtdFunc++;
    strcpy(instrucao[linhaAtual].label, registrador);
    linhaAtual--;
}

void load(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "lw");

    indice = parametro(linha, indice);

    char aux[10];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);
    
    int pos;

    if (strcmp(registrador, "0") == 0){
        pos = 0;
    } else {
        pos = busca_indice(registrador, function, "var");
        if (pos == -1){
            pos = busca_indice(registrador, "Global", "var");
        }
    }
    sprintf(aux, "%d", pos);
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "($%d)", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void load_v(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "lw");

    indice = parametro(linha, indice);

    char aux[10];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);
    int pos;

    pos = busca_indice(registrador, function, "var");
    if (pos == -1){
        pos = busca_indice(registrador, "Global", "var");
    }
    
    sprintf(aux, "%d", pos);
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);
    sprintf(aux, "($%d)", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void store(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "sw");

    indice = parametro(linha, indice);

    char aux[10];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);
    int pos;

    if (strcmp(registrador, "0") == 0){
        pos = 0;
    } else {
        pos = busca_indice(registrador, function, "var");
        if (pos == -1){
            pos = busca_indice(registrador, "Global", "var");
        }
    }

    sprintf(aux, "%d", pos);
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "($%d)", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void call(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "jal");

    indice = parametro(linha, indice);
    indice = parametro(linha, indice);

    int i = 0;
    while (strcmp(posicaoLabel[i].name, registrador) != 0){
        i++;
    }
    
    sprintf(aux, "%d", posicaoLabel[i].posicao);
    strcpy(instrucao[linhaAtual].reg1, aux);
    strcpy(instrucao[linhaAtual].reg2, "");
    strcpy(instrucao[linhaAtual].regD, "");

    contaQtdArgumento = contaQtdParametros;
    contaQtdParametros = 0;
}

void callOut(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "output");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);
    strcpy(instrucao[linhaAtual].reg2, "");
    strcpy(instrucao[linhaAtual].regD, "");
}

void if_conditional(char *linha, int indice){
    indice = parametro(linha, indice);
    indice = parametro(linha, indice);

    strcpy(instrucao[linhaAtual - 1].regD, registrador);
    linhaAtual--;
}

void branchNE(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "bne");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    strcpy(instrucao[linhaAtual].regD, "");
}

void branchEQ(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "beq");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    strcpy(instrucao[linhaAtual].regD, "");
}

void branchGE(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "bge");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    strcpy(instrucao[linhaAtual].regD, "");
}

void branchGT(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "bgt");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    strcpy(instrucao[linhaAtual].regD, "");
}

void branchLE(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "ble");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    strcpy(instrucao[linhaAtual].regD, "");
}

void branchLT(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "blt");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    strcpy(instrucao[linhaAtual].regD, "");
}

void ret(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "jr");
    strcpy(instrucao[linhaAtual].reg1, "$ra");
    strcpy(instrucao[linhaAtual].reg2, "");
    strcpy(instrucao[linhaAtual].regD, "");
}

void add(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "add");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void sub(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "sub");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);
    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void div_(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "div");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void mult(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "mult");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void param(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "add");
    indice = parametro(linha, indice);

    char aux[5];
    char num[5];

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    strcpy(instrucao[linhaAtual].reg2, "$0,");

    sprintf(num, "$a%d", contaQtdParametros);
    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(num));
    contaQtdParametros++;
    strcpy(instrucao[linhaAtual].regD, aux);
}

void arg(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "sw");
    indice = parametro(linha, indice);

    if (strcmp(instrucao[linhaAtual - 1].instruc, "lw") != 0)
        argumentoAtual = 0;

    char aux[5];
    char num[5];

    sprintf(num, "$a%d", argumentoAtual);
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(num));

    printf("\nargAtual: %d\n", argumentoAtual);

    argumentoAtual++;

    strcpy(instrucao[linhaAtual].reg1, aux);
    indice = parametro(linha, indice);

    int pos;

    pos = busca_indice(registrador, function, "var");
    if (pos == -1){
        pos = busca_indice(registrador, "Global", "var");
    }

    sprintf(aux, "%d", pos);
    strcpy(instrucao[linhaAtual].reg2, aux);

    sprintf(aux, "($%d)", 0);
    strcpy(instrucao[linhaAtual].regD, aux);
}

void alloc(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "sw");
    strcpy(instrucao[linhaAtual].reg1, "$0,");

    indice = parametro(linha, indice);
    int pos;
    pos = busca_indice(registrador, function, "var");
    if (pos == -1){
        pos = busca_indice(registrador, "Global", "var");
    }

    char aux[5];
    sprintf(aux, "%d", pos);
    strcpy(instrucao[linhaAtual].reg2, aux);

    sprintf(aux, "($%d)", 0);
    strcpy(instrucao[linhaAtual].regD, aux);
}

void load_varg(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "addi");
    indice = parametro(linha, indice);

    char aux[10];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);

    indice = parametro(linha, indice);
    int pos;

    pos = busca_indice(registrador, function, "var");
    if (pos == -1){
        pos = busca_indice(registrador, "Global", "var");
    }

    sprintf(aux, "%d", pos);
    strcpy(instrucao[linhaAtual].regD, aux);

    strcpy(instrucao[linhaAtual].reg1, "$0,");
}

void limpa(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "clear");
}

void jumpMain(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "jmain");
}

void escreveNoArquivo(){
    for (int i = 1; i < linhaAtual; i++){
        fprintf(arquivoAssembly, "%s %s%s%s", instrucao[i].instruc, instrucao[i].reg1, instrucao[i].reg2, instrucao[i].regD);

        if (strcmp(instrucao[i].label, "") != 0){
            fprintf(arquivoAssembly, "\t//%s", instrucao[i].label);
        }
        fprintf(arquivoAssembly, "\n");
    }
}

void geraAssembly(){
    char read[51];

    strcpy(function, "");

    instrucao = (ASSEMBLY *)malloc(sizeof(ASSEMBLY));
    posicaoRetornoLabel = (int *)malloc(sizeof(int) * returnLabel() + 1);
    posicaoLabel = (LABEL *)malloc(sizeof(LABEL));

    while (fgets(read, 50, arquivoIntermediario) != NULL){

        while (read[0] != '('){
            fgets(read, 50, arquivoIntermediario);
        }

        instrucao = (ASSEMBLY *)realloc(instrucao, (linhaAtual + 1) * sizeof(ASSEMBLY));
        nome_instrucao(read);

        linhaAtual++;
    }
    labels();
    escreveNoArquivo();

    free(instrucao);
    free(posicaoRetornoLabel);
    free(posicaoLabel);
}

void nome_instrucao(char *read){
    char instruc[15];
    int j = 0, i;
    for (i = 1; read[i] != ',' && i < 15; i++){
        instruc[j] = read[i];
        j++;
    }

    i++;
    instruc[j] = '\0';

    if (strcmp(instruc, "CONST") == 0){
        addi(read, i);

    } else if (strcmp(instruc, "GOTO") == 0){
        jump(read, i);

    } else if (strcmp(instruc, "LABEL") == 0){
        label(read, i);

    } else if (strcmp(instruc, "FUNC") == 0){
        funcao(read, i);

    } else if (strcmp(instruc, "LOAD") == 0){
        load(read, i);

    } else if (strcmp(instruc, "STORE") == 0){
        store(read, i);

    } else if (strcmp(instruc, "CALL") == 0){
        call(read, i);

    } else if (strcmp(instruc, "CALL_OUT") == 0){
        callOut(read, i);

    } else if (strcmp(instruc, "IF") == 0){
        if_conditional(read, i);

    } else if (strcmp(instruc, "DIF") == 0){
        branchNE(read, i);

    } else if (strcmp(instruc, "IGUAL") == 0){
        branchEQ(read, i);

    } else if (strcmp(instruc, "MAIORIG") == 0){
        branchGE(read, i);

    } else if (strcmp(instruc, "MAIOR") == 0){
        branchGT(read, i);

    } else if (strcmp(instruc, "MENORIG") == 0){
        branchLE(read, i);

    } else if (strcmp(instruc, "MENOR") == 0){
        branchLT(read, i);

    } else if (strcmp(instruc, "END") == 0){
        linhaAtual--;

    } else if (strcmp(instruc, "RETURN") == 0){
        ret(read, i);

    } else if (strcmp(instruc, "ADD") == 0){
        add(read, i);

    } else if (strcmp(instruc, "SUB") == 0){
        sub(read, i);

    } else if (strcmp(instruc, "DIV") == 0){
        div_(read, i);

    } else if (strcmp(instruc, "MULT") == 0){
        mult(read, i);

    } else if (strcmp(instruc, "ALLOC") == 0){
        alloc(read, i);

    } else if (strcmp(instruc, "ALLOC_V") == 0){
        alloc(read, i);

    } else if (strcmp(instruc, "PARAM") == 0){
        arg(read, i);

    } else if (strcmp(instruc, "ARG") == 0){
        param(read, i);

    } else if (strcmp(instruc, "LOAD_VARG") == 0){
        load_varg(read, i);

    } else if (strcmp(instruc, "LOAD_V") == 0){
        load_v(read, i);

    } else if (strcmp(instruc, "CLEAR") == 0){
        limpa(read, i);

    } else if (strcmp(instruc, "JUMP_MAIN") == 0){
        jumpMain(read, i);

    } else {
        strcpy(instrucao[linhaAtual].instruc, instruc);
    }
}