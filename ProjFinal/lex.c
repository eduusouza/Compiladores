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
    free(token->lexema);
}

int hash(char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        
        hash += key[i];
    }

    return (hash);
}


void insertTHash(HNode* table[], char* key, int value) {

    int index = hash(key);
    
    HNode* newNode = (HNode*)malloc(sizeof(HNode));

    strncpy(newNode->key, key, sizeof(newNode->key));
    newNode->value = value;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {

        newNode->next = table[index];
        table[index] = newNode;

        printf("Colisao %d\n", index);
    }
}

int searchTHash(HNode* table[], char* key) {
    int index = hash(key);

    HNode* current = table[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
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

    int estado = 0, tipoC, index_lexema = 0;
    char c, aux;

    //Inicializando tabela hash
    HNode* hashTable[TAM_THASH];
    for (int i = 0; i < TAM_THASH; i++) {
        hashTable[i] = NULL;
    }
     
    //Inserindo palavras reservadas
    insertTHash(hashTable, "else", ELSE);
    insertTHash(hashTable, "if", IF);
    insertTHash(hashTable, "int", INT);
    insertTHash(hashTable, "return", RETURN);
    insertTHash(hashTable, "void", VOID);
    insertTHash(hashTable, "while", WHILE);

    allocateToken(token);
    token->endOfFile = 0;
    token->validacao = 0;
    
    while (estado != -1){

        switch(estado){
            case 0:
                c = getNextChar(info);
                tipoC = cType(c);

                if (tipoC == 0){              //Caso c seja uma letra, ele pode ser um identificador ou uma palavra reservada
                    estado = 1;
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                } else if (tipoC == 1){       //Caso c seja um digito, ele pode ser um numero
                    estado = 2;
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                } else if (tipoC == 2){       //Caso c seja um simbolo, ele pode ser um operador ou um delimitador
                    estado = 3;
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                } else {
                    if(c == ' '){             //Caso c seja um espaço, tab, quebra de linha ou retorno de carro, ele é ignorado
                        break;
                    } else if(c == '\n'){
                        break;
                    } else if(c == '\t'){
                        break;
                    } else if(c == '\r'){
                        break;
                    } else {                  //Caso c seja diferente dos caracteres acima, ele não pertence a linguagem
                        token->validacao = 1;
                        estado = -1;
                        token->lexema[index_lexema] = c;
                        index_lexema++; 
                        break;
                    }
                }
                break;
                
            case 1:
                c = getNextChar(info);
                tipoC = cType(c);
                if (tipoC == 0){             //Caso ainda seja uma letra, mantem o estado atual e consome o caracter
                    estado = 1;
                    token->lexema[index_lexema] = c;
                    index_lexema++;                    
                } else {
                    ungetChar(info);        //Caso não seja uma letra, devolve o caracter para o buffer e finaliza o lexema
                    estado = -1;

                    //Faz a busca na tabela hash para verificar se é palavra reservada
                    int pesquisa = searchTHash(hashTable, token->lexema);

                    (pesquisa != -1) ? (token->type = pesquisa) : (token->type = ID); 

                    token->linha = info->linha;
                }
                break;

            case 2:
                c = getNextChar(info);
                tipoC = cType(c);
                if (tipoC == 1){             //Caso ainda seja um digito, mantem o estado atual e consome o caracter
                    estado = 2;
                    token->lexema[index_lexema] = c;
                    index_lexema++;                    
                } else {
                    ungetChar(info);        //Caso não seja um digito, devolve o caracter para o buffer e finaliza o lexema
                    estado = -1;
                    token->type = NUM;
                    token->linha = info->linha;
                }
                break;

            case 3:                        //Caso c seja um simbolo, ele pode ser um operador ou um delimitador
                switch(c){
                    case '+':
                        token->type = SOMA;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '-':
                        token->type = SUB;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '*':
                        token->type = MULT;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '/':
                        token->type = DIV;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '<':
                        token->type = MENOR;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '>':
                        token->type = MAIOR;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '=':
                        token->type = IGUAL;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '!':
                        token->type = DIF;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case ';':
                        token->type = PONTO_VIRG;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case ',':
                        token->type = VIRG;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '(':
                        token->type = ABRE_PARENT;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case ')':
                        token->type = FECHA_PARENT;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '[':
                        token->type = ABRE_COLCH;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case ']':
                        token->type = FECHA_COLCH;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '{':
                        token->type = ABRE_CHAVES;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                    case '}':
                        token->type = FECHA_CHAVES;
                        token->linha = info->linha;
                        estado = -1;
                        break;
                }
                break; 
            default:
                estado = -1;
                break;       
        }

    }

    if(c == EOF){      //Caso c seja o fim do arquivo, ele é ignorado e o token é finalizado
        token->endOfFile = 1;
    }    
    return *token;
}