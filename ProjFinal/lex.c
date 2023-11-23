#include "lex.h"

void allocateBuffer(tipoBuffer *info){
    info->buffer = malloc(sizeof(char *) * TAM_BUFFER);
}

void deallocateBuffer(tipoBuffer *info){
    free(info->buffer);
}

void allocateToken(Token *token){
    token->lexema = malloc(sizeof(Token));
}

void deallocateToken(Token *token){
    free(token);
}


char getNextChar(tipoBuffer *info){

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

char peekNextChar(tipoBuffer *info){

    char c = fgetc(info->arquivo);
    if(c == EOF){
        return EOF;
    }
    fseek(info->arquivo, -1, SEEK_CUR);
    return c;
}

int isSymbol(char c){
    char simbolos[] = {'+', '-', '*', '/', '<', '>', '=', '!', ';', ',', '(', ')', '[', ']', '{', '}'};
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

Token getNextToken(tipoBuffer *info, Token *token){

    int aceita[4] = {0, 0, 0, 1};
    int T[4][3] = {
        {2, 1, 3},
        {3, 1, 3},
        {2, 3, 3},
        {-1, -1, -1}};
    int avance[4][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    int estado = 0, novoEstado, tipoC, erro = 0, index_lexema = 0;
    char c;

    c = getNextChar(info);
    tipoC = cType(c);
    token->lexema[index_lexema] = c;
    index_lexema += 1;
    token->endOfFile = 0;
    
    if(c == EOF){
        token->endOfFile = 1;
        return *token;
    }
    
    while ((!aceita[estado]) && (!erro)){

           
        //caso o tipo do caracter não se encaixar em nenhum previsto
        if (tipoC == 3){
            erro = 1;
            break;        
        //caso o tipo se encaixar como simbolo, será necessário tratar cada caso
        }else if(tipoC == 2){
            switch (c){
                case '+':
                    novoEstado = T[estado][tipoC];
                    token->type = SOMA;
                    break;                    
                case '-':
                    novoEstado = T[estado][tipoC];
                    token->type = SUB;
                    break;                                      
                case '*':
                    novoEstado = T[estado][tipoC];
                    token->type = MULT;
                    break;
                case ';':
                    novoEstado = T[estado][tipoC];
                    token->type = PONTO_VIRG;
                    break;
                case ',':
                    novoEstado = T[estado][tipoC];
                    token->type = VIRG;
                    break;
                case '(':
                    novoEstado = T[estado][tipoC];
                    token->type = ABRE_PARENT;
                    break;
                case ')':
                    novoEstado = T[estado][tipoC];
                    token->type = FECHA_PARENT;
                    break;
                case '[':
                    novoEstado = T[estado][tipoC];
                    token->type = ABRE_COLCH;
                    break;
                case ']':
                    novoEstado = T[estado][tipoC];
                    token->type = FECHA_COLCH;
                    break;
                case '{':
                    novoEstado = T[estado][tipoC];
                    token->type = ABRE_CHAVES;
                    break;
                case '}':
                    novoEstado = T[estado][tipoC];
                    token->type = FECHA_CHAVES;
                    break;
                case '<':
                    //verifica se proximo caracter é =
                    printf("%c", peekNextChar(info));
                    if(peekNextChar(info) == '='){
                        c = getNextChar(info);
                        novoEstado = 3;
                        token->type = MENOR_IGUAL;
                    } else {
                        novoEstado = T[estado][tipoC];
                        token->type = MENOR;
                    }
                    break; 
                case '>':
                    if(peekNextChar(info) == '='){
                        c = getNextChar(info);
                        novoEstado = 3;
                        token->type = MAIOR_IGUAL;
                    } else {
                        novoEstado = T[estado][tipoC];
                        token->type = MAIOR;
                    }                    
                    break;
                case '=':
                    if(peekNextChar(info) == '='){
                        token->type = IGUAL;
                    } else {
                        token->type = ATRIB;
                    }
                    break;
                case '!':
                    if(peekNextChar(info) == '='){
                        token->type = DIF;
                    } else{
                        token->type =  -1;
                    }
                    break;
                case '/':
                    if(peekNextChar(info) == '*'){
                        while(1){
                            c = getNextChar(info);
                            if(c == '*'){
                                if(getNextChar(info) == '/'){
                                    break;
                                }
                            }
                        }
                    } else{
                        token->type = DIV;
                    }
                    break;
            } 
        } else {
            novoEstado = T[estado][tipoC];
        }
        
        //classificação do lexema
        if(novoEstado == 3){
            switch(estado){
                case 1:
                    //verificar se não é palavra reservada

                    token->type = ID;
                    break;
                case 2:
                    token->type = NUM;
                    break;
            }
        }
        
        if(avance[estado][tipoC] == 1){
            c = getNextChar(info);
            tipoC = cType(c);
            token->lexema[index_lexema] = c;
            index_lexema += 1;
        }
        estado = novoEstado;            
    }

    if(erro == 1){
        printf("TRATAR");
    } 

    token->linha = info->linha;
    return *token;
}