#include "funcs.h"

void allocate_buffer(tipoBuffer *info){
  info->buffer = malloc(sizeof(char*)*TAM_BUFFER);
}

void deallocate_buffer(tipoBuffer *info){
  free(info->buffer);
}

char get_next_char(tipoBuffer *info){
  
  if (info->flag == 0){
    char* endFile = fgets(info->buffer, TAM_BUFFER, info->arquivo);
    info->flag = 1;
    info->index = 0;

    if(endFile == NULL){
      return EOF;
    }  

    if (info->buffer[0] == '\n'){
      info->flag = 0;
      return '\n';
    }
  }

  int length = strlen(info->buffer);

  if (info->index == length-1){
    info->flag = 0;
  }

  info->index++;  
  return info->buffer[(info->index-1)];
}