#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

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

int inserir(Lista* lista, struct elemento retangulo) {
    if(lista == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = retangulo;

    no->prox = lista->inicio;
    lista->inicio = no;

    lista->qtd++;
    return 1;
}

int remover(Lista* lista, int id) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio, *ant = NULL;

    while(atual != NULL && atual->dado.id != id) {
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

    return 1;
}

float calcularArea(Lista* lista, struct elemento* retangulo) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio;

    while(atual != NULL && atual->dado.id != retangulo->id) {
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    retangulo->base = atual->dado.base;
    retangulo->altura = atual->dado.altura;

    return atual->dado.altura * atual->dado.base;
}

void imprimir(Lista* lista) {
    if(lista == NULL) {
        return;
    }

    noLista* atual = lista->inicio;

    while(atual != NULL) {
        printf("ID: %d\n", atual->dado.id);
        printf("Altura(h): %.2f\n", atual->dado.altura);
        printf("Base(b): %.2f\n", atual->dado.base);

        printf("---------------------------------\n");

        atual = atual->prox;
    }
}

void apagarLista(Lista* lista) {
    if(lista != NULL) {
        while(lista->inicio != NULL) {
            noLista* aux = lista->inicio;
            lista->inicio = lista->inicio->prox;
            free(aux);
        }
        free(lista);
    }
}
