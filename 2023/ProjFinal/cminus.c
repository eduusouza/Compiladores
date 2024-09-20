#include "lex.h"

int main(int argc, char *argv[]){   

    //Declaração de variáveis
    int i;
    tipoBuffer info;
    Token token;
    info.flag = 0;
    info.index = 0;
    info.linha = 1;
    token.endOfFile = 0;
    token.linha = 1;

    //Verificando se o número de parâmetros está correto
    if (argc != 2){
        printf("Numero de parametros esta errado\n");
        return 0;
    }

    //Verificando se o arquivo pode ser aberto
    info.arquivo = fopen(argv[1], "r");
    if (info.arquivo == NULL){
        printf("Nao foi possivel abrir os arquivos\n");
        return 0;
    }

    //Alocando memória para o buffer e para o token
    allocateBuffer(&info);
    allocateToken(&token);

    //Criando tabela hash para associar tokens das palavras reservadas
    HNode* reservadasHT[TAM_THASH];
    for (int i = 0; i < TAM_THASH; i++) {
        reservadasHT[i] = NULL;
    }
     
    //Inserindo palavras reservadas na tabela
    insertTHash(reservadasHT, "else", ELSE);
    insertTHash(reservadasHT, "if", IF);
    insertTHash(reservadasHT, "int", INT);
    insertTHash(reservadasHT, "return", RETURN);
    insertTHash(reservadasHT, "void", VOID);
    insertTHash(reservadasHT, "while", WHILE);

    //Criando tabela hash para associar símbolos a colunas da tabela do dfa
    HNode* auxHT[TAM_THASH];
    for (int i = 0; i < TAM_THASH; i++) {
        auxHT[i] = NULL;
    }
     
    //Inserindo palavras reservadas na tabela
    insertTHash(auxHT, "/", 2);
    insertTHash(auxHT, "<", 3);
    insertTHash(auxHT, ">", 4);
    insertTHash(auxHT, "=", 5);
    insertTHash(auxHT, "!", 6);
    insertTHash(auxHT, "*", 7);
    insertTHash(auxHT, "+", 8);
    insertTHash(auxHT, "-", 9);
    insertTHash(auxHT, "(", 10);
    insertTHash(auxHT, ")", 11);
    insertTHash(auxHT, "[", 12);
    insertTHash(auxHT, "]", 13);
    insertTHash(auxHT, "{", 14);
    insertTHash(auxHT, "}", 15);
    insertTHash(auxHT, ",", 16);
    insertTHash(auxHT, ";", 17);
    insertTHash(auxHT, "1", NUM);
    insertTHash(auxHT, "4", MENOR);
    insertTHash(auxHT, "5", MENOR_IGUAL);
    insertTHash(auxHT, "6", MAIOR);
    insertTHash(auxHT, "7", MAIOR_IGUAL);
    insertTHash(auxHT, "9", MENOR_IGUAL);
    insertTHash(auxHT, "10", ATRIB);
    insertTHash(auxHT, "11", IGUAL);
    insertTHash(auxHT, "12", DIV);
    insertTHash(auxHT, "15", MULT);
    insertTHash(auxHT, "16", SOMA);
    insertTHash(auxHT, "17", SUB);
    insertTHash(auxHT, "18", ABRE_PARENT);
    insertTHash(auxHT, "19", FECHA_PARENT);
    insertTHash(auxHT, "20", ABRE_COLCH);
    insertTHash(auxHT, "21", FECHA_COLCH);
    insertTHash(auxHT, "22", ABRE_CHAVES);
    insertTHash(auxHT, "23", FECHA_CHAVES);
    insertTHash(auxHT, "24", VIRG);
    insertTHash(auxHT, "25", PONTO_VIRG);

    //Lendo o arquivo e imprimindo os tokens
    while (token.endOfFile != 1){
        
        //Pegando o próximo token
        token = getNextToken(&info, &token, reservadasHT, auxHT);
        
        //Verificando se o arquivo acabou
        if (token.endOfFile == 1){
            break;
        }
        
        //Verificando se o token é válido e imprimindo
        if (token.validacao == 1){
            printf("Erro lexico: %s, Linha: %d\n", token.lexema, token.linha);
        } else if (token.type) {
            printf("Linha: %d, Lexema: %s, ", token.linha, token.lexema);
            if(token.type == IF){
                printf("Token: IF\n");
            } else if (token.type == ELSE){
                printf("Token: ELSE\n");
            } else if (token.type == INT){
                printf("Token: INT\n");
            } else if (token.type == RETURN){
                printf("Token: RETURN\n");
            } else if (token.type == VOID){
                printf("Token: VOID\n");
            } else if (token.type == WHILE){
                printf("Token: WHILE\n");
            } else if (token.type == WRITE){
                printf("Token: WRITE\n");
            } else if (token.type == SOMA){
                printf("Token: SOMA\n");
            } else if (token.type == SUB){
                printf("Token: SUB\n");
            } else if (token.type == MULT){
                printf("Token: MULT\n");
            } else if (token.type == DIV){
                printf("Token: DIV\n");
            } else if (token.type == MENOR){
                printf("Token: MENOR\n");
            } else if (token.type == MENOR_IGUAL){
                printf("Token: MENOR_IGUAL\n");
            } else if (token.type == MAIOR){
                printf("Token: MAIOR\n");
            } else if (token.type == MAIOR_IGUAL){
                printf("Token: MAIOR_IGUAL\n");
            } else if (token.type == ATRIB){
                printf("Token: ATRIB\n");
            } else if (token.type == DIF){
                printf("Token: DIF\n");
            } else if (token.type == IGUAL){
                printf("Token: IGUAL\n");
            } else if (token.type == PONTO_VIRG){
                printf("Token: PONTO_VIRG\n");
            } else if (token.type == VIRG){
                printf("Token: VIRG\n");
            } else if (token.type == ABRE_PARENT){
                printf("Token: ABRE_PARENT\n");
            } else if (token.type == FECHA_PARENT){
                printf("Token: FECHA_PARENT\n");
            } else if (token.type == ABRE_COLCH){
                printf("Token: ABRE_COLCH\n");
            } else if (token.type == FECHA_COLCH){
                printf("Token: FECHA_COLCH\n");
            } else if (token.type == ABRE_CHAVES){
                printf("Token: ABRE_CHAVES\n");
            } else if (token.type == FECHA_CHAVES){
                printf("Token: FECHA_CHAVES\n");
            } else if (token.type == NUM){
                printf("Token: NUM\n");
            } else if (token.type == ID){
                printf("Token: ID\n");
            }
        }
        
    } 
    deallocateToken(&token);
    deallocateBuffer(&info);    

    fclose(info.arquivo);
    return 0;
}