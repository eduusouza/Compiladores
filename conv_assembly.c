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

        } else if (strcmp(instrucao[i].instruc, "jfunc") == 0){
            char aux[5];
            
            j = 0;
            while (strcmp(posicaoLabel[j].name, instrucao[i].func) != 0){
               j++;
            }
    
            sprintf(aux, "%d", posicaoLabel[j].posicao);
            strcpy(instrucao[i].reg1, aux);

        } else if (strcmp(instrucao[i].instruc, "bne") == 0 ||
        strcmp(instrucao[i].instruc, "beq") == 0){
            
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

    } else if (strcmp(regAux, "$r0") == 0){
        return $r0;

    } else if (strcmp(regAux, "$v0") == 0){
        return $v0;

    } else if (strcmp(regAux, "$a0") == 0){
        return $a0;

    } else if (strcmp(regAux, "$a1") == 0){
        return $a1;

    } else if (strcmp(regAux, "$a2") == 0){
        return $a2;

    } else if (strcmp(regAux, "$a3") == 0){
        return $a3;

    } else if (strcmp(regAux, "$a4") == 0){
        return $a4;

    } else if (strcmp(regAux, "$a5") == 0){
        return $a5;

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

    } else if (strcmp(regAux, "$fp") == 0){
        return $fp;

    } else if (strcmp(regAux, "$ra") == 0){
        return $ra;

    } else if (strcmp(regAux, "$v0") == 0){
        return $v0;

    } else if (strcmp(regAux, "$sp") == 0){
        return $sp;
    }
}

void addi(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "addi");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);
    sprintf(aux, "%s,", registrador);
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);
    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void subi(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "subi");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);
    sprintf(aux, "%s,", registrador);
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);
    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);
}

void jump(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "jump");

    indice = parametro(linha, indice);

    strcpy(instrucao[linhaAtual].reg1, registrador);
    strcpy(instrucao[linhaAtual].reg2, "");
    strcpy(instrucao[linhaAtual].regD, "");
}

void jump_reg(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "jreg");
    char aux[5];

    indice = parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);
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

    strcpy(instrucao[linhaAtual].instruc, "addi");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);
    
    sprintf(aux, "%d,", linhaAtual + 2);
    strcpy(instrucao[linhaAtual].reg2, aux);

    ultimo_parametro(linha, indice);

    sprintf(aux, "$zero", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].regD, aux);

    contaQtdArgumento = contaQtdParametros;
    contaQtdParametros = 0;
}

void callOut(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "output");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, "");
    strcpy(instrucao[linhaAtual].reg2, aux);
    strcpy(instrucao[linhaAtual].regD, "");
}

void callIn(char *linha, int indice){
    char aux[5];

    strcpy(instrucao[linhaAtual].instruc, "input");

    indice = parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, "");
    strcpy(instrucao[linhaAtual].reg2, aux);
    strcpy(instrucao[linhaAtual].regD, "");
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

    ultimo_parametro(linha, indice);
    strcpy(instrucao[linhaAtual].regD, registrador);
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

    ultimo_parametro(linha, indice);
    strcpy(instrucao[linhaAtual].regD, registrador);
}

void set(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "set");
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

void sbte(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "sbte");
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

void sbt(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "sbt");
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

void slte(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "slte");
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

void slt(char *linha, int indice){

    strcpy(instrucao[linhaAtual].instruc, "slt");
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

void jumpFunction(char *linha, int indice){
    char aux[20];

    strcpy(instrucao[linhaAtual].instruc, "jfunc");

    indice = parametro(linha, indice);
    strcpy(instrucao[linhaAtual].func, registrador);
}

void halt(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "halt");
}

void nop(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "nop");
}

void move(char *linha, int indice){
    strcpy(instrucao[linhaAtual].instruc, "move");
    indice = parametro(linha, indice);

    char aux[5];
    sprintf(aux, "$%d,", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg1, aux);

    indice = parametro(linha, indice);

    sprintf(aux, "$%d", buscaValorEnderecoRegistrador(registrador));
    strcpy(instrucao[linhaAtual].reg2, aux);
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

    if (strcmp(instruc, "LI") == 0){
        addi(read, i);

    } else if (strcmp(instruc, "JUMP") == 0){
        jump(read, i);

    } else if (strcmp(instruc, "JUMP_REG") == 0){
        jump_reg(read, i);

    } else if (strcmp(instruc, "SUBI") == 0){
        subi(read, i);

    } else if (strcmp(instruc, "LABEL") == 0){
        label(read, i);

    } else if (strcmp(instruc, "NOP") == 0){
        funcao(read, i);

    } else if (strcmp(instruc, "LOAD") == 0){
        load(read, i);

    } else if (strcmp(instruc, "STORE") == 0){
        store(read, i);

    } else if (strcmp(instruc, "CALL") == 0){
        call(read, i);

    } else if (strcmp(instruc, "CALL_OUT") == 0){
        callOut(read, i);
    
    } else if (strcmp(instruc, "CALL_IN") == 0){
        callIn(read, i);

    } else if (strcmp(instruc, "BNE") == 0){
        branchNE(read, i);

    } else if (strcmp(instruc, "BEQ") == 0){
        branchEQ(read, i);

    } else if (strcmp(instruc, "IGUAL") == 0){
        set(read, i);

    } else if (strcmp(instruc, "MAIORIG") == 0){
        sbte(read, i);

    } else if (strcmp(instruc, "MAIOR") == 0){
        sbt(read, i);

    } else if (strcmp(instruc, "MENORIG") == 0){
        slte(read, i);

    } else if (strcmp(instruc, "MENOR") == 0){
        slt(read, i);

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

    } else if (strcmp(instruc, "LOAD_VARG") == 0){
        load_varg(read, i);

    } else if (strcmp(instruc, "LOAD_V") == 0){
        load_v(read, i);

    } else if (strcmp(instruc, "JUMP_FUNC") == 0){
        jumpFunction(read, i);

    } else if (strcmp(instruc, "HALT") == 0){
        halt(read, i);

    } else if (strcmp(instruc, "MOVE") == 0){
        move(read, i);

    } else {
        strcpy(instrucao[linhaAtual].instruc, instruc);
    }
}