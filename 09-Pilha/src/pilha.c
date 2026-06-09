#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

typedef struct tipoNo noPilha;
