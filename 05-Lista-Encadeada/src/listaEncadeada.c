#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista;


Lista* criarLista() {
    Lista* list = (Lista*) calloc(1, sizeof(Lista));

    if(list != NULL) {
        *list = NULL;
    }

    return list;
}
