#include "funcs.h"

int main(int argc, char *argv[]){

  int i;
  char c;
  tipoBuffer info;
  info.flag = 0;
  info.index = 0;

  if (argc != 2){
    printf("Numero de parametros esta errado\n");
    return 0;
  }
  
  info.arquivo = fopen(argv[1],"r");
  if (info.arquivo == NULL){
    printf("Nao foi possivel abrir os arquivos\n");
    return 0;
  }

  allocate_buffer(&info);
  
  while ((c = get_next_char(&info)) != EOF){
    printf("%c", c);
  }
  
  deallocate_buffer(&info);
  
  fclose(info.arquivo);
  return 0;
}