#include "funcs.h"

void allocate_buffer(tipoBuffer *info){
    info->buffer = malloc(sizeof(char *) * TAM_BUFFER);
}

void deallocate_buffer(tipoBuffer *info){
    free(info->buffer);
}

Token* inputToken(int type, char* lexema, int linha){
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = type;
    token->lexema = strdup(lexema);
    token->linha = linha;
    return token;
}

void deallocate_token(Token *token){
    free(token);
}

char get_next_char(tipoBuffer *info){

    if (info->flag == 0){
        char* endFile = fgets(info->buffer, TAM_BUFFER, info->arquivo);
        info->flag = 1;
        info->index = 0;

        if(endFile == NULL){
            return EOF;
        }  

        if (info->buffer[0] == '\n'){
            info->flag = 0;
            info->linha++;
            return '\n';
        }
    }

    int length = strlen(info->buffer);

    if (info->index == length-1){
        info->flag = 0;
    }

    if (info->buffer[info->index-1] == '\n'){
        info->linha++;
    }

    info->index++;  
    return info->buffer[(info->index-1)];
}

int isSymbol(char c){
    for (int i = 0; i < 16; i++){
        if (c == simbolos[i]){
            return 1;
        }
    }
    return 0;
}

int cType(char c){
    if (isalpha(c)){
        return 0;
    } else if (isdigit(c)){
        return 1;
    } else if (isSymbol(c)){
        return 2;
    } else {
        return 3;
    }
}