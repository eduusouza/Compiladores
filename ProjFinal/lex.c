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

int cType(char c){
    if (isalpha(c)){
        return 0;
    } else if (isdigit(c)){
        return 1;
    } else {
        return 2;
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
    memset(token->lexema, '\0', sizeof(token->lexema));
    
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
                } else {
                    switch (c){               //Caso c seja um simbolo, ele pode ser um operador ou um delimitador
                        case '+':
                            estado = 3;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;

                        case '-':
                            estado = 4;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;

                        case '*':
                            estado = 5;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;

                        case '/':                               //Se for barra, não consome o caracter e avança de estado
                            estado = 6;                            
                            break;

                        case '<':
                            estado = 9;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case '>':
                            estado = 10;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case '=':
                            estado = 11;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case '!':
                            estado = 12;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case ';':
                            estado = 13;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case ',':
                            estado = 14;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case '(':
                            estado = 15;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case ')':
                            estado = 16;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case '[':
                            estado = 17;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case ']':
                            estado = 18;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;

                        case '{':
                            estado = 19;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                        
                        case '}':
                            estado = 20;
                            token->lexema[index_lexema] = c;
                            index_lexema++;
                            break;
                                       
                    default:
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
                            token->linha = info->linha;
                            break;
                        }
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

            case 3:                        
                token->type = SOMA;         //Atualiza o tipo de token e finaliza o lexema
                token->linha = info->linha;
                estado = -1;
                break;
            
            case 4:
                token->type = SUB;          //Atualiza o tipo de token e finaliza o lexema
                token->linha = info->linha;
                estado = -1;
                break;

            case 5:
                token->type = MULT;         //Atualiza o tipo de token e finaliza o lexema
                token->linha = info->linha;
                estado = -1;
                break;

            case 6:                         //Caso c seja uma barra, ele pode ser um operador de divisão ou um comentário
                aux = getNextChar(info);
                if (aux == '*'){
                    estado = 7;
                } else {
                    token->lexema[index_lexema] = c;        //Caso não seja um comentário, devolve o caracter para o buffer e finaliza o lexema
                    index_lexema++;
                    ungetChar(info);
                    token->type = DIV;
                    token->linha = info->linha;
                    estado = -1;
                }
                break;
            
            case 7:
                while((c = getNextChar(info)) != '*'){     //Consome todos caracteres até encontrar um asterisco
                    if (c == EOF){
                        printf("Erro lexico: comentario nao fechado.\n");
                        exit(1);
                        break;
                    }
                }
                estado = 8;
                break;
            
            case 8:                          //Caso c seja um asterisco, ele pode ser o final de um comentário ou não
                c = getNextChar(info);         
                if (c == '/'){
                    estado = -1;
                } else {
                    estado = 7;
                }
                break;

            case 9:
                c = getNextChar(info);      //Caso c seja um menor, ele pode ser um operador de menor ou menor igual
                if (c == '='){
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                    token->type = MENOR_IGUAL;
                    token->linha = info->linha;
                    estado = -1;
                } else {
                    ungetChar(info);
                    token->type = MENOR;
                    token->linha = info->linha;
                    estado = -1;
                }
                break;

            case 10:
                c = getNextChar(info);               //Caso c seja um maior, ele pode ser um operador de maior ou maior igual
                if (c == '='){
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                    token->type = MAIOR_IGUAL;
                    token->linha = info->linha;
                    estado = -1;
                } else {
                    ungetChar(info);
                    token->type = MAIOR;
                    token->linha = info->linha;
                    estado = -1;
                }                
                break;

            case 11:           
                c = getNextChar(info);                //Caso c seja um igual, ele pode ser um operador de igual ou de atribuição
                if (c == '='){
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                    token->type = IGUAL;
                    token->linha = info->linha;
                    estado = -1;
                } else {
                    ungetChar(info);
                    token->type = ATRIB;
                    token->linha = info->linha;
                    estado = -1;
                }
                break;

            case 12:                                //Caso c seja um exclamação, ele pode ser um operador de diferente ou não
                c = getNextChar(info);
                if (c == '='){
                    token->lexema[index_lexema] = c;
                    index_lexema++;
                    token->type = DIF;
                    token->linha = info->linha;
                    estado = -1;
                } else {
                    ungetChar(info);
                    token->type = IGUAL;
                    token->linha = info->linha;
                    estado = -1;
                }
                break;

            case 13:
                token->type = PONTO_VIRG;
                token->linha = info->linha;
                estado = -1;
                break;

            case 14:
                token->type = VIRG;
                token->linha = info->linha;
                estado = -1;
                break;

            case 15:
                token->type = ABRE_PARENT;
                token->linha = info->linha;
                estado = -1;
                break;
    
            case 16:
                token->type = FECHA_PARENT;
                token->linha = info->linha;
                estado = -1;
                break;

            case 17:
                token->type = ABRE_COLCH;
                token->linha = info->linha;
                estado = -1;
                break;

            case 18:
                token->type = FECHA_COLCH;
                token->linha = info->linha;
                estado = -1;
                break;

            case 19:
                token->type = ABRE_CHAVES;
                token->linha = info->linha;
                estado = -1;
                break;

            case 20:
                token->type = FECHA_CHAVES;
                token->linha = info->linha;
                estado = -1;
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

/*

Bug string lexema com caracter a mais
Imprimir valor dos Tokens enum

*/