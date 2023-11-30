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

    info->index++;
    if (info->buffer[info->index-1] == '\n'){
        info->linha++;
    }      
    return info->buffer[(info->index-1)];
}

void ungetChar(tipoBuffer *info){
    info->index--;
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
    char c, aux;

    allocateToken(token);
    token->endOfFile = 0;
    
    while ((!aceita[estado]) && (!erro)){

        c = getNextChar(info);
        tipoC = cType(c);  
        //caso o tipo do caracter não se encaixar em nenhum previsto
        if (tipoC == 3){
            if(c == ' '){
                break;
            } else if(c == '\n'){
                break;
            } else if(c == '\t'){
                break;
            } else if(c == '\r'){
                break;
            } else {
                erro = 1;
            }
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
                    if((aux = getNextChar(info)) == '='){
                        token->lexema[index_lexema] = c;
                        c = aux;
                        index_lexema += 1;
                        novoEstado = 3;
                        token->type = MENOR_IGUAL;
                    } else {
                        novoEstado = T[estado][tipoC];
                        token->type = MENOR;
                        ungetChar(info);
                    }
                    break; 
                case '>':
                    if((aux = getNextChar(info)) == '='){
                        token->lexema[index_lexema] = c;
                        c = aux;
                        index_lexema += 1;
                        novoEstado = 3;
                        token->type = MAIOR_IGUAL;
                    } else {
                        novoEstado = T[estado][tipoC];
                        token->type = MAIOR;
                        ungetChar(info);
                    }                    
                    break;
                case '=':
                    if((aux = getNextChar(info)) == '='){
                        token->lexema[index_lexema] = c;
                        c = aux;
                        index_lexema += 1;
                        token->type = IGUAL;
                    } else {
                        token->type = ATRIB;
                        ungetChar(info);
                    }
                    break;
                case '!':
                    if((aux = getNextChar(info)) == '='){
                        token->lexema[index_lexema] = c;
                        c = aux;
                        index_lexema += 1;
                        token->type = DIF;
                    } else{
                        token->type =  -1;
                        ungetChar(info);
                    }
                    break;
                case '/':
                    if((aux = getNextChar(info)) == '*'){
                        while(1){
                            c = getNextChar(info);
                            if(c == '*'){
                                if(getNextChar(info) == '/'){
                                    break;
                                }
                            }
                        }
                    } else{
                        ungetChar(info);
                        token->type = DIV;
                    }
                    break;
            }
            token->lexema[index_lexema] = c;
            index_lexema += 1;
        } else {
            token->lexema[index_lexema] = c;
            index_lexema += 1;
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
            if ((tipoC != 3) && (c != EOF)){
                token->linha = info->linha;
                token->lexema[index_lexema] = c;
                index_lexema += 1;
            } else if (c == EOF){
                token->endOfFile = 1;
                return *token;
            }
        }

        estado = novoEstado;                    
    }    
    if(erro == 1){
        printf("Erro lexico: %s, Linha: %d\n", token->lexema, token->linha);
    } 
    return *token;
}