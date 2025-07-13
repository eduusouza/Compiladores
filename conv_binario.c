#include "globals.h"
#include <string.h>
#include "conv_binario.h"

static int linhaAtual = 0;

int valorR1 = 0, valorR2 = 0, valorRS = 0, valorImediato = 0;
char registradores[10];

int buscaRegistrador(char *linha, int indice)
{
    int j = 0, auxIndice;

    for (auxIndice = indice + 1; auxIndice < 40 && linha[auxIndice] != ',' && linha[auxIndice] != '\n' && linha[auxIndice] != ')'; auxIndice++)
    {
        registradores[j] = linha[auxIndice];
        j++;
    }
    registradores[j] = '\0';

    return auxIndice + 1;
}

int buscaImediato(char *linha, int indice)
{
    int j = 0, auxIndice;

    for (auxIndice = indice; auxIndice < 40 && linha[auxIndice] != ',' && linha[auxIndice] != '\n' && linha[auxIndice] != '('; auxIndice++) // pega buscaImediato
    {
        registradores[j] = linha[auxIndice];
        j++;
    }
    registradores[j] = '\0';

    return auxIndice + 1;
}

void instrucaoADD(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd0, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd0}; // add\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoSUB(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd0, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd1}; // sub\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoMULT(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd0, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd2}; // mult\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoDIV(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd0, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd3}; // div\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoINC(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd0, 5'd%d, 5'd0, 5'd%d, 5'd0, 6'd4}; // inc\n", linhaAtual, valorR1, valorRS);
}

void instrucaoDEC(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd0, 5'd%d, 5'd0, 5'd%d, 5'd0, 6'd5}; // dec\n", linhaAtual, valorR1, valorRS);
}

void instrucaoAND(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd1, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd0}; // and\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoOR(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd1, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd1}; // or\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoNOT(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd1, 5'd%d, 5'd0, 5'd%d, 5'd0, 6'd2}; // not\n", linhaAtual, valorR1, valorRS);
}

void instrucaoXOR(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd1, 5'd%d, 5'd%d, 5'd%d, 5'd0, 6'd3}; // xor\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoADDI(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd2, 5'd%d, 5'd%d, 16'd%d}; // addi\n", linhaAtual, valorR2, valorImediato, valorR1);
}

void instrucaoMOVE(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd3, 5'd%d, 5'd%d, 16'd0}; // move\n", linhaAtual, valorR1, valorR2);
}

void instrucaoSLT(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd4, 5'd%d, 5'd%d, 5'd%d, 16'd0}; // slt\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoJUMP(char *valorLinha, int valorIndice)
{
    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd5, 26'd%d}; // jump\n", linhaAtual, valorImediato - 1);
}

void instrucaoLOAD(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd6, 5'd%d, 5'd%d, 16'd%d}; // lw\n", linhaAtual, valorR2, valorR1, valorImediato);
}

void instrucaoSTORE(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd7, 5'd%d, 5'd%d, 16'd%d}; // sw\n", linhaAtual, valorR2, valorR1, valorImediato);
}

void instrucaoINPUT(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd8, 5'd0, 5'd%d, 16'd0}; //input\n", linhaAtual, valorR1); 
}

void instrucaoOUTPUT(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd9, 5'd%d, 5'd0, 16'd0}; //output\n", linhaAtual, valorR1); 
}

void instrucaoBEQ(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd10, 5'd%d, 5'd%d, 16'd%d}; // beq\n", linhaAtual, valorR1, valorR2, valorImediato - 1);
}

void instrucaoBNE(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd11, 5'd%d, 5'd%d, 16'd%d}; // bne\n", linhaAtual, valorR1, valorR2, valorImediato - 1);
}

void instrucaoNOP(char *valorLinha, int valorIndice)
{
    fprintf(arquivoBinario, "Memoria[%d] = {6'd12, 26'd0}; // nop\n", linhaAtual);
}

void instrucaoHALT(char *valorLinha, int valorIndice)
{
    fprintf(arquivoBinario, "Memoria[%d] = {6'd13, 26'd0}; // halt\n", linhaAtual);
}

void instrucaoSLTE(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd14, 5'd%d, 5'd%d, 5'd%d, 16'd0}; // slte\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoSBT(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd15, 5'd%d, 5'd%d, 5'd%d, 16'd0}; // sbt\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoSBTE(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd16, 5'd%d, 5'd%d, 5'd%d, 16'd0}; // sbte\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoSET(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorRS = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd17, 5'd%d, 5'd%d, 5'd%d, 16'd0}; // set\n", linhaAtual, valorR1, valorR2, valorRS);
}

void instrucaoSUBI(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR2 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd18, 5'd%d, 5'd%d, 16'd%d}; // subi\n", linhaAtual, valorR2, valorR1, valorImediato);
}

void instrucaoJR(char *valorLinha, int valorIndice)
{
    valorIndice = buscaRegistrador(valorLinha, valorIndice);
    valorR1 = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd19, 5'd%d, 5'd0, 5'd0, 11'd0}; // jr\n", linhaAtual, valorR1);
}

void instrucaoJFUNC(char *valorLinha, int valorIndice)
{
    valorIndice = buscaImediato(valorLinha, valorIndice);
    valorImediato = atoi(registradores);

    fprintf(arquivoBinario, "Memoria[%d] = {6'd5, 26'd%d}; //jump func \n", linhaAtual, valorImediato - 1); // começa pulando para a main
}


void instrucoesBinarias(char *valorLinha)
{
    char instrucao[15];

    int j = 0, valorIndice;

    for (valorIndice = 0; valorLinha[valorIndice] != ' ' && valorIndice < 15; valorIndice++) // pega a instrucao do assembly
    {
        instrucao[j] = valorLinha[valorIndice];

        j++;
    }

    valorIndice++;

    instrucao[j] = '\0';

    if (strcmp(instrucao, "add") == 0){
        instrucaoADD(valorLinha, valorIndice);
    } else if (strcmp(instrucao, "sub") == 0){
        instrucaoSUB(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "mult") == 0){
        instrucaoMULT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "div") == 0){
        instrucaoDIV(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "inc") == 0){
        instrucaoINC(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "dec") == 0){
        instrucaoDEC(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "and") == 0){
        instrucaoAND(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "or") == 0){
        instrucaoOR(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "not") == 0){
        instrucaoNOT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "xor") == 0){
        instrucaoXOR(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "addi") == 0){
        instrucaoADDI(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "move") == 0){
        instrucaoMOVE(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "slt") == 0){
        instrucaoSLT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "jfunc") == 0){
        instrucaoJFUNC(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "lw") == 0){
        instrucaoLOAD(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "sw") == 0){
        instrucaoSTORE(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "input") == 0){
        instrucaoINPUT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "output") == 0){
        instrucaoOUTPUT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "beq") == 0){
        instrucaoBEQ(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "bne") == 0){
        instrucaoBNE(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "nop") == 0){
        instrucaoNOP(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "halt") == 0){
        instrucaoHALT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "slte") == 0){
        instrucaoSLTE(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "sbt") == 0){
        instrucaoSBT(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "sbte") == 0){
        instrucaoSBTE(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "set") == 0){
        instrucaoSET(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "subi") == 0){
        instrucaoSUBI(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "jreg") == 0){
        instrucaoJR(valorLinha, valorIndice);
    }
    else if (strcmp(instrucao, "jump") == 0){
        instrucaoJUMP(valorLinha, valorIndice);
    }
}

void geraBinario()
{
    char valorLinha[25];

    while (fgets(valorLinha, 25, arquivoAssembly) != NULL)
    {
        instrucoesBinarias(valorLinha);

        linhaAtual++;
    }
}
