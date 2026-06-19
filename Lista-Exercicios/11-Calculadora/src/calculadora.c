#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

struct tipoLista {
    struct tipoNo* inicio;
    int qtd;
};

typedef struct tipoNo noLista;

Lista* criarLista() {
    Lista* list = (Lista*) calloc(1, sizeof(Lista));

    if(list != NULL) {
        list->inicio = NULL;
        list->qtd = 0;
    }
    return list;
}

int inserirFinal(Lista* lista, struct elemento valor) {
   if(lista == NULL) {
    return 0;
   }

   noLista* no = (noLista*) calloc(1, sizeof(noLista));

   if(no == NULL) {
    return 0;
   }

   no->dado = valor;
   no->prox = NULL;

   if(lista->inicio == NULL) {
    lista->inicio = no;
    lista->qtd++;

    return 1;
   }

   noLista* atual = lista->inicio;

   while(atual->prox != NULL) {
    atual = atual->prox;
   }

   atual->prox = no;
   lista->qtd++;

   return 1;
}

int removerFinal(Lista* lista, struct elemento* valor) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio;

    if(atual->prox == NULL) {
        *valor = atual->dado;

        free(atual);
        lista->qtd--;
        lista->inicio = NULL;

        return 1;
    }

    while(atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    noLista* ultimo = atual->prox;

    *valor = ultimo->dado;

    free(ultimo);
    lista->qtd--;
    atual->prox = NULL;

    return 1;
}

int listaVazia(Lista* lista) {
    if(lista == NULL) {
        return 1;
    }

    if(lista->inicio == NULL) {
        return 1;
    }

    return 0;
}

int tamanhoLista(Lista* lista) {
    if (lista == NULL) {
        return 0;
    } 

    return lista->qtd; 
}

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

void liberarLista(Lista* lista) {
    if(lista != NULL) {
        while(lista->inicio != NULL) {
            noLista* atual = lista->inicio;

            lista->inicio = lista->inicio->prox;

            free(atual);
        }
        free(lista);
    }
}
