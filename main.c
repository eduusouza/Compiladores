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

int yywrap()
{
  return 1;
}

int main(int argc, char *argv[])
{
  TreeNode *arvoreSintatica;
  char nomeArquivo[120];

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

    printf("\nCódigo finalizado\n");

    printf("\nFIM\n");
  }

  fclose(source);

  return 0;
}
