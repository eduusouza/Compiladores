#include "lex.h"

int main(int argc, char *argv[]){

    int i;
    tipoBuffer info;
    Token token;
    info.flag = 0;
    info.index = 0;
    info.linha = 0;

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
    allocateToken(&token);
    
    token = getNextToken(&info, &token);
    while (token.endOfFile != 1){
        printf("Linha: %d, Lexema: %s, TOKEN: %d", token.linha, token.lexema, token.type);
        token = getNextToken(&info, &token);
    } 
    
    deallocateBuffer(&info);
    deallocateToken(&token);    

    fclose(info.arquivo);
    return 0;
}