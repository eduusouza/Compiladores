#include "globals.h"

#define NO_PARSE FALSE
#define NO_ANALYSE FALSE
#define NO_CODE FALSE

int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = TRUE;

FILE *arquivoIntermediario;

// int TraceScan = FALSE;
// int TraceParse = FALSE;
// int TraceAnalyze = FALSE;

int Error = FALSE;

int main(int argc, char **argv){

    TreeNode *arvoreSintatica;
    line_number = 0;

    if (argc != 2){
        printf("Quantidade de entradas incorreta.\n");
        return 1;
    }
    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL){
        printf("Arquivo de input nao encontrado\n");
    }

    printf("Inicio da compilacao.\n");

    #if NO_PARSE
        while (getToken()!=YYEOF);
    #else
        arvoreSintatica = parse();
        if (TraceParse){
            printf("\nArvore Sintatica:\n");
            printTree(arvoreSintatica);
        }
    
    #if !NO_ANALYZE
        if(!Error){
            if (TraceAnalyze)
              printf("\nCriando tabela de símbolos...\n");
            printf("\n");
            buildSymtab(arvoreSintatica);
            if (TraceAnalyze)
                printf("\nInício da verificação de tipos...\n");
            typeCheck(arvoreSintatica);
            if (TraceAnalyze)
                printf("\nFim da verificação de tipos\n");
        }
    
    #if !NO_CODE
        if(Error){
            //Logica para gerar codigo intermediario
            arquivoIntermediario = fopen("codigoIntermediario.txt", "w");

            geraIntermediario(arvoreSintatica);

            fclose(arquivoIntermediario);
        }
    #endif
    #endif
    #endif

    printf("\nFim da compilação.\n");

    fclose(inputFile);
    return 0;
}