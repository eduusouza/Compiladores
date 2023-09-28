#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_BUFFER 100

typedef struct {
  char* buffer;
  int index;
  FILE *arquivo;
  int flag;
} tipoBuffer;

void allocate_buffer(tipoBuffer*);

void deallocate_buffer(tipoBuffer*);

char get_next_char(tipoBuffer*);