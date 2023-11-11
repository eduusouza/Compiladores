 #include "funcs.h"

int main(int argc, char *argv[]){

    int i, estado, novoEstado, tipoC, erro;
    char c;
    tipoBuffer info;
    Token* token;
    info.flag = 0;
    info.index = 0;
    info.linha = 0;
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
        {0, 0, 0}
    };

    if (argc != 2){
        printf("Numero de parametros esta errado\n");
        return 0;
    }

    info.arquivo = fopen(argv[1], "r");
    if (info.arquivo == NULL){
        printf("Nao foi possivel abrir os arquivos\n");
        return 0;
    }

    allocate_buffer(&info);

    while ((c = get_next_char(&info)) != EOF){
        estado = 0;
        tipoC = cType(c);
        erro = 0;

        while ((!aceita[estado]) && (!erro)){
            
            if (tipoC == 3){
                erro = 1;
                break;
            }else if(tipoC == 2){
                switch (c){
                    case '+':
                        novoEstado = T[estado][tipoC];
                    case '-':
                        
                    case '*':

                    case ';':

                    case ',':

                    case '(':

                    case ')':

                    case '[':

                    case ']':

                    case '{':

                    case '}':

                    case '<':

                    case '>':

                    case '=':

                    case '!':

                    case '/':
                }


            }

            novoEstado = T[estado][tipoC];

            //classificação do lexema
            if(novoEstado == 3){
                switch(estado){
                    case 0:

                    case 1:
                        printf("NUM");
                    case 2:
                        printf("ID");
                }
            }

            if(avance[estado][tipoC] == 1){
                c = get_next_char(&info);
                tipoC = cType(c);
            }
            estado = novoEstado;

            
        }

        if(erro == 1){
            printf("TRATAR");
        }
        printf("Linha: %d, Lexema: %s, TOKEN: %d", token->linha, token->lexema, token->type);
    }   

    deallocate_buffer(&info);
    deallocate_token(&token);

    fclose(info.arquivo);
    return 0;
}