#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

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

int inserirOrdenado(Lista* lista, struct elemento valor) {
    if(lista == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = valor;

    noLista* ant = NULL, *atual = lista->inicio;

    while(atual != NULL && atual->dado.numeros < valor.numeros) {
        ant = atual;
        atual = atual->prox;
    }

    if(atual == lista->inicio) {
        no->prox = lista->inicio;
        lista->inicio = no;
    } else {
        ant->prox = no;
        no->prox = atual;
    }

    lista->qtd++;
    return 1;
}

int removerElemento(Lista* lista, int valor) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* ant = NULL, *atual = lista->inicio;

    while(atual != NULL && atual->dado.numeros != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    if(atual == lista->inicio) {
        lista->inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    
    free(atual);
    lista->qtd--;

    return 0;
}

Lista* mergeListas(Lista* L1, Lista* L2) {
    if(L1 == NULL && L2 == NULL) {
        return NULL;
    }

    Lista* L3 = criarLista();

    if(L3 == NULL) {
        return NULL;
    }
    
    if(L1 != NULL) {
        noLista* atual = L1->inicio;

        while(atual != NULL) {
            inserirOrdenado(L3, atual->dado);
            atual = atual->prox;
        }
    }

    if(L2 != NULL) {
        noLista* atual = L2->inicio;

        while(atual != NULL) {
            inserirOrdenado(L3, atual->dado);
            atual = atual->prox;
        }
    }

    return L3;
}

void imprimirLista(Lista* lista) {
    if(lista == NULL) {
        return;
    }

    noLista* atual = lista->inicio;
    int i = 1;

    while(atual != NULL) {
        printf("%d° Valor: %d\n", i++, atual->dado.numeros);

        printf("-----------------------------------\n");

        atual = atual->prox;
    }
}

void liberarLista(Lista* lista) {
    if(lista != NULL) {

        while(lista->inicio != NULL) {
            noLista* aux = lista->inicio;
            lista->inicio = lista->inicio->prox;

            free(aux);
        }
        free(lista);
    }
}
