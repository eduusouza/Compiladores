#include "lex.h"

//Função que aloca memória para o buffer
void allocateBuffer(tipoBuffer *info){
    info->buffer = malloc(sizeof(char *) * TAM_BUFFER);
}

//Função que desaloca memória para o buffer
void deallocateBuffer(tipoBuffer *info){
    free(info->buffer);
}

//Função que aloca memória para o token
void allocateToken(Token *token){
    token->lexema = malloc(sizeof(Token));
}

//Função que desaloca memória para o token
void deallocateToken(Token *token){
    free(token->lexema);
}

//Função que calcula o hash de uma string
int hash(char* key) {

    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        
        hash += key[i];
    }

    return (hash);
}

//Função que insere um elemento na tabela hash
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

        // printf("Colisao %d\n", index);
    }
}

//Função que busca um elemento na tabela hash
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

//Função que retorna o próximo caracter do buffer
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


//Função que retorna a coluna do caracter na matriz de transição
int classificaCaracter(char c, HNode *auxHT[]){ 

    if (isalpha(c)){              //Caso c seja uma letra, ele pode ser um identificador ou uma palavra reservada
        return 0; 
    } else if (isdigit(c)){       //Caso c seja um digito, ele pode ser um numero
        return 1;
    } else {
        char ch[2] = {c, '\0'};  //Caso c seja um caracter especial, ele pode ser um simbolo ou um operador
        return searchTHash(auxHT, ch);
    }
}

//Função que retorna o próximo token
Token getNextToken(tipoBuffer *info, Token *token, HNode* reservadasHT[], HNode* auxHT[]){

    int estado = 0, tipoC, index_lexema;
    char c, aux;
    
    //Declaração da matriz de transição
    int T[27][18]={
        {2,1,12,4,6,10,8,15,16,17,18,19,20,21,22,23,24,25}, // 0
        {3,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 1
        {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 2
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 3
        {3,3,3,3,3,5,3,3,3,3,3,3,3,3,3,3,3,3}, // 4
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 5
        {3,3,3,3,3,7,3,3,3,3,3,3,3,3,3,3,3,3}, // 6
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 7
        {3,3,3,3,3,9,3,3,3,3,3,3,3,3,3,3,3,3}, // 8
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 9
        {3,3,3,3,3,11,3,3,3,3,3,3,3,3,3,3,3,3}, // 10
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 11
        {3,3,3,3,3,3,3,13,3,3,3,3,3,3,3,3,3,3}, // 12
        {13,13,13,13,13,13,13,14,13,13,13,13,13,13,13,13,13,13}, // 13
        {13,13,0,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13}, // 14
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 15
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 16
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 17
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 18
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 19
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 20
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 21
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 22
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 23
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 24
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, // 25
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3} // 26
    };

    //Declaração da matriz de avanço
    int avance[27][18] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 0
        {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 1
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 2
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 3
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, // 4
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 5
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, // 6
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 7
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, // 8
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 9
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, // 10
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 11
        {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}, // 12
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 13
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 14
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 15
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 16
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 17
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 18
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 19
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 20
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 21
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 22
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 23
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 24
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 25
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} // 26
    };

    //Declaração do vetor de estados de aceitação
    int aceita[27] = {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    int erro = 0, novoEstado, cEntrada, oldState;
    token->endOfFile = 0;
    token->validacao = 0;    

    //Pegando o primeiro caracter do arquivo
    c = getNextChar(info); 

    if(c == EOF){      //Caso c seja o fim do arquivo, a flag é setada para 1
        token->endOfFile = 1;
    }

    //Enquanto o estado não for de aceitação, o caracter é classificado e o estado é atualizado
    while(!aceita[estado]){

        if(estado == 0){
            index_lexema = 0;
            memset(token->lexema, '\0', sizeof(token->lexema));        //Limpando dados do Lexema
        }
        
        //Caracter é classificado
        cEntrada = classificaCaracter(c, auxHT);
        
        //Caso o caracter não seja válido, é retornado um erro
        if(cEntrada == -1){
            
            //Caso seja um destes caracteres especiais e esteja dentro de um comentário, retorna para o estado 13 e consome o próximo caracter
            if((c == ' ')|| (c == '\n') || (c == '\t')|| (c == '\r')){
                if (estado == 14 || estado == 13){
                    estado = 13;
                    c = getNextChar(info); 
                    
                }else{

                    //Caso seja um destes caracteres especiais e não esteja dentro de um comentário, ele é ignorado    
                    while((c == ' ')|| (c == '\n') || (c == '\t')|| (c == '\r')){
                        c = getNextChar(info);
                    }
                    
                    //Se tiver saindo de comentário, não é necessário classificar token, apenas ignorar os espaços
                    if (oldState != 14){
                        ungetChar(info);
                        novoEstado = 3;
                        
                    }
                    
                }
                
            } else{
                
                //Caso seja um caracter inválido, é retornado um erro
                token->validacao = 1;
                token->lexema[index_lexema] = c;
                index_lexema++; 
                token->linha = info->linha;
                break;
            }
        } else{
            
            //Caso o caracter seja válido, o estado é atualizado
            novoEstado = T[estado][cEntrada];
            if(avance[estado][cEntrada]){
                token->lexema[index_lexema] = c;
                index_lexema++;
                token->linha = info->linha;
                c = getNextChar(info);
            }else{
                ungetChar(info);
            }
            
        }
        
        oldState = estado;
        estado = novoEstado;            
    }  

    //Caso o estado seja de aceitação, o token é classificado
    char estadoString[3];
    sprintf(estadoString, "%d", oldState);
    token->lexema[index_lexema] = '\0';
    
    //Caso o estado seja 2, é necessário verificar se o token é uma palavra reservada
    if (oldState == 2){
        
        int pesquisa = searchTHash(reservadasHT, token->lexema);
        (pesquisa != -1) ? (token->type = pesquisa) : (token->type = ID);
    }else{
        token->type = searchTHash(auxHT, estadoString);       //Caso não seja, o token é classificado normalmente
    }   
        
    return *token;
}