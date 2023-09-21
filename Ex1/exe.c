#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcs.h"

int main(int argc, char *argv[]){

  int size_buffer, i;
  char c;
  FILE *arq1;
  tipoBuffer info;

  size_buffer = atoi(argv[2]);

  if (argc != 3){
    printf("Numero de parametros esta errado\n");
    return 0;
  }
  
  info.size_buffer = size_buffer;
  info.index = 0;
  allocate_buffer(&info);
  
  arq1 = fopen(argv[1],"r");

  if (arq1 == NULL){
    printf("Nao foi possivel abrir os arquivos\n");
    return 0;
  }
  
  while ((c = fgetc(arq1)) != EOF){
    replace_print(c, &info);
  }
  
  if (c == EOF){
    for (i = 0; i < info.index; i++){
      printf("%c", info.buffer[i]);
    }
  }
  
  deallocate_buffer(&info);
  
  fclose(arq1);
  return 0;
}