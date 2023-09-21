#include "funcs.h"

void allocate_buffer(tipoBuffer *info){
  info->buffer = malloc(sizeof(char*)*TAM_BUFFER);
}

void deallocate_buffer(tipoBuffer *info){
  free(info->buffer);
}

char get_next_char(tipoBuffer *info){
  char c;
  int length, i;

  if (info->flag == 0){
    if (fgets(info->buffer, TAM_BUFFER, info->arquivo))
    info->flag = 1;
  }
  
  length = strlen(info->buffer);
  
  if (info->index == length-1){
    info->flag = 0;
  }

  c = info->buffer[(info->index)];
  info->index++;
  
  if (c == '\n'){
    info->line++;
  }
  
  return c;
}