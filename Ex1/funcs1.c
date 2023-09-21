#include "funcs.h"

void allocate_buffer(tipoBuffer *info){
  info->buffer = malloc(sizeof(char*)*info->size_buffer);
}

void deallocate_buffer(tipoBuffer *info){
  free(info->buffer);
}

void replace_print(char c, tipoBuffer *info){
  int i;
  if (info->index < info->size_buffer){
    if (isupper(c)){
      c = tolower(c);
    } else {
      c = toupper(c);
    }
    info->buffer[info->index] = c;
    info->index++;
  }
  if (info->index == info->size_buffer){
    for (i = 0; i < info->index; i++){      
      printf("%c", info->buffer[i]);
    }
    info->index = 0;
  }
}