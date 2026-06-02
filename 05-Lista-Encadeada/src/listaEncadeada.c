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

int inserirOrdenada(Lista* inicio, struct elemento valor) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if((no == NULL)) {
        return 0;
    }

    if((*inicio == NULL)) {
        no->dado = valor;
        no->prox = *inicio;

        *inicio = no;

        return 1;

    } else {
        no->dado = valor;

        noLista *ant, *atual = *inicio;


        while(atual != NULL && atual->dado.num < valor.num) {
            ant = atual;
            atual = atual->prox;
        }

        if(atual != NULL && atual->dado.num == valor.num) {
            free(no);
            return 0;
        }

        if(atual == *inicio) {
            no->prox = *inicio;
            *inicio = no;
        } else {
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int removerElemento(Lista*inicio, int valor) {
    if(inicio == NULL) {
        return 0;
    }

    if((*inicio == NULL)) {
        return 0;
    }

    noLista *ant, *no = *inicio;

    while (no != NULL && no->dado.num != valor) {
        ant = no;
        no = no->prox;
    }

    if(no == NULL) {
        return 0;
    }

    if(no == (*inicio)) {
        *inicio = no->prox;
    } else {
        ant->prox = no->prox;
    }

    free(no);
    return 1;
}

void imprimirLista(Lista* inicio) {
    if(inicio == NULL) {
        return;
    }

    noLista *no = *inicio;

    int i = 1;
    while(no != NULL) {
        printf("%d° Valor: %d\n", i++, no->dado.num);

        no = no->prox;
    }
}
