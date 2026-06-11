#include <stdio.h>
#include <stdlib.h>
#include "union.h"

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

int insereElemento(Lista* lista, struct elemento valor) {
    if(lista == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = aluno;

    no->prox = lista->inicio;
    lista->inicio = no;
    lista->qtd++;

    return 1;
}

int removeElemento(Lista* lista, int num) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* ant, *atual = lista->inicio;

    while(atual != NULL && atual->dado.numeros != num) {
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


Lista* uniaoListas(Lista* L1, Lista* L2) {
    if(L1 == NULL && L2 == NULL) {
        return 0;
    }

    Lista* L3 = criarLista();
    if(L3 == NULL) {
        return 0;
    }

    if(L1 != NULL) {
        noLista* atual = L1->inicio;

        while(atual != NULL) {
            insereElemento(L3, atual->dado);

            atual = atual->prox;
        }
    }

    if(L2 != NULL) {
        noLista* atual = L2->inicio;

        while(atual != NULL) {
            insereElemento(L3, atual->dado);

            atual = atual->prox;
        }
    }

    return L3;
}

void imprimeLista(Lista* lista) {
    if(lista == NULL) {
        return;
    }

    noLista* atual = lista->inicio;
    int i = 1;

    while(atual != NULL) {
        printf("%d° Valor: %d\n", i++, atual->dado.numeros);

        atual = atual->prox;
    }
}

void apagaLista(Lista* lista) {
    if(lista != NULL) {
        while(lista->inicio != NULL) {
            noLista* aux = lista->inicio;

            lista->inicio = lista->inicio->prox;
            free(aux);
        }
        free(lista);
    }
}
