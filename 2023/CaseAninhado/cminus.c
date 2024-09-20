#include "lex.h"

int main(int argc, char *argv[]){

    int i;
    tipoBuffer info;
    Token token;
    info.flag = 0;
    info.index = 0;
    info.linha = 1;
    token.endOfFile = 0;
    token.linha = 1;

    if (argc != 2){
        printf("Numero de parametros esta errado\n");
        return 0;
    }

    info.arquivo = fopen(argv[1], "r");
    if (info.arquivo == NULL){
        printf("Nao foi possivel abrir os arquivos\n");
        return 0;
    }

    allocateBuffer(&info);
    
    while (token.endOfFile != 1){
        token = getNextToken(&info, &token);
        if (token.endOfFile == 1){
            break;
        }

        if (token.validacao == 1){
            printf("Erro lexico: %s, Linha: %d\n", token.lexema, token.linha);
        } else {
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
        deallocateToken(&token);
    } 
    
    deallocateBuffer(&info);    

    fclose(info.arquivo);
    return 0;
}