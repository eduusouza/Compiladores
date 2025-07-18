#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util_analyze.h"
#include <string.h>
#include "scan.h"
#include "parse.h"
#include "analyze.h"
#include "cgen.h"
#include "util.h"

int lineno = 0;
int isRecursive = 0;

FILE *source;
FILE *arquivoIntermediario;
FILE *arquivoAssembly;
FILE *arquivoBinario;

int EchoSource = FALSE;
int TraceScan = FALSE;
int TraceParse = TRUE;
int TraceAnalyze = TRUE;
int TraceCode = FALSE;

int Error = FALSE;

RECURSIVE *recursivas = NULL;

int yywrap()
{
  return 1;
}

int main(int argc, char *argv[])
{
  TreeNode *arvoreSintatica;
  char nomeArquivo[120];
  recursivas = (RECURSIVE *)malloc(sizeof(RECURSIVE));

  if (argc != 2){
    printf("Quantidade de entradas incorreta.\n");
    return 1;
  }

  strcpy(nomeArquivo, argv[1]);

  source = fopen(nomeArquivo, "r");

  if (source == NULL){
    printf("Arquivo '%s' não encontrado\n", nomeArquivo);
    exit(1);
  }

  printf("\nCompilação do código C-: %s\n", nomeArquivo);

  arvoreSintatica = parse();

  if (TraceParse && !Error){
    printf("\nÁRVORE SINTÁTICA:\n");
    printTree(arvoreSintatica);
  }

  if (!Error){
    if (TraceAnalyze){
      printf("\nCONSTRUINDO TABELA DE SIMBOLOS\n");
    }

    implementaTabela(arvoreSintatica);

    if (TraceAnalyze){
      printf("\nANALISADOR SEMÂNTICO\n");  
      checaTipoDoNo(arvoreSintatica);
    }
  }

  if (!Error){
    printf("\nGERANDO CODIGO INTERMEDIARIO\n");

    // Gerador de código intermediário
    char *intermediario;

    int tamanho = strcspn(nomeArquivo, ".");

    intermediario = (char *)calloc(tamanho + 4, sizeof(char));

    strncpy(intermediario, nomeArquivo, tamanho);
    strcat(intermediario, ".inter");
    arquivoIntermediario = fopen(intermediario, "w");

    geraIntermediario(arvoreSintatica);
    fclose(arquivoIntermediario);

    // Gerador de código assembly
    char *assembly;

    tamanho = strcspn(nomeArquivo, ".");

    assembly = (char *)calloc(tamanho + 4, sizeof(char));
    strncpy(assembly, nomeArquivo, tamanho);
    strcat(assembly, ".assembly");

    arquivoAssembly = fopen(assembly, "w"); // abre intermediario .assembly para escrita

    if (arquivoAssembly == NULL)
    {
      printf("Unable to open a %s\n", assembly);
      exit(1);
    }

    arquivoIntermediario = fopen(intermediario, "r"); // abre intermediario .inter para leitura

    if (arquivoIntermediario == NULL)
    {
      printf("Unable to open b %s\n", intermediario);
      exit(1);
    }

    geraAssembly();

    fclose(arquivoIntermediario);
    fclose(arquivoAssembly);

    // Gerador de código binario
    char *binario;

    tamanho = strcspn(nomeArquivo, ".");

    binario = (char *)calloc(tamanho + 4, sizeof(char));
    strncpy(binario, nomeArquivo, tamanho);
    strcat(binario, ".binario");

    arquivoBinario = fopen(binario, "w");

    if (arquivoBinario == NULL)
    {
      printf("Não foi possível abrir o binario %s\n", binario);
      exit(1);
    }

    arquivoAssembly = fopen(assembly, "r");
    
    if (arquivoAssembly == NULL)
    {
      printf("Não foi possível abrir o assembly %s\n", assembly);
      exit(1);
    }

    geraBinario();

    fclose(arquivoBinario);
    fclose(arquivoAssembly);

    printf("\nCódigo finalizado\n");

    printf("\nFIM\n");
  }
  free(recursivas);
  fclose(source);

  return 0;
}
