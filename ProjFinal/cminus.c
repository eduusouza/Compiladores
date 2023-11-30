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
            printf("Linha: %d, Lexema: %s, Token: %d\n", token.linha, token.lexema, token.type);
        deallocateToken(&token);
    } 
    
    deallocateBuffer(&info);    

    fclose(info.arquivo);
    return 0;
}