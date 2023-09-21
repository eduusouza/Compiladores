#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
  char* buffer;
  int size_buffer;
  int index;
} tipoBuffer;

void allocate_buffer(tipoBuffer*);

void deallocate_buffer(tipoBuffer*);

void replace_print(char c, tipoBuffer*);