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

Lista* intersecao(Lista* l1, Lista* l2) {
    if(l1 == NULL || l2 == NULL) {
        return NULL;
    }

    Lista* l3 = criarLista();

    if((*l1 == NULL || *l2 == NULL)) {
        return l3;
    }

    noLista *atual1 = *l1, *atual2 = *l2;

    while(atual1 != NULL && atual2 != NULL) {

        if(atual1->dado.num == atual2->dado.num) {
            inserirOrdenada(l3, atual1->dado);

            atual1 = atual1->prox;
            atual2 = atual2->prox;
        } else 
        if(atual1->dado.num < atual2->dado.num) {
            atual1 = atual1->prox;
        } else {
            atual2 = atual2->prox;
        }
    }

    return l3;
}

Lista* diferenca(Lista* l1, Lista* l2) {
    if(l1 == NULL || l2 == NULL) {
        return NULL;
    }

    Lista* l4 = criarLista();

    if(*l1 == NULL || *l2 == NULL) {
        return l4;
    }
    
    noLista* atual1 = *l1, *atual2 = *l2; 

    while(atual1 != NULL && atual2 != NULL) {
        if(atual1->dado.num == atual2->dado.num) {
            atual1 = atual1->prox;
            atual2 = atual2->prox;
        } else 
        if(atual1->dado.num < atual2->dado.num) {
            inserirOrdenada(l4, atual1->dado);
            atual1 = atual1->prox;
        } else {
            atual2 = atual2->prox;
        }
    }

    while (atual1 != NULL) {
        inserirOrdenada(l4, atual1->dado);
        atual1 = atual1->prox;
    }

    return l4;
}

Lista* merge(Lista* l1, Lista* l2) {
    if(l1 == NULL || l2 == NULL) {
        return NULL;
    }

    Lista* l5 = criarLista();

    if(*l1 == NULL || *l2 == NULL) {
        return l5;
    }

    noLista* atual1 = *l1, *atual2 = *l2;

    while(atual1 != NULL && atual2 != NULL) {
        if(atual1->dado.num == atual2->dado.num) {
            inserirOrdenada(l5, atual1->dado);
            atual1 = atual1->prox;
            atual2 = atual2->prox;
        } else

        if(atual1->dado.num < atual2->dado.num) {
            inserirOrdenada(l5, atual1->dado);
            atual1 = atual1->prox;
        } else {
            inserirOrdenada(l5, atual2->dado);
            atual2 = atual2->prox;
        }
    }

    return l5;
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

void liberarLista(Lista* inicio) {
    if(inicio == NULL) {
        return;
    }

    noLista* atual = *inicio, *proximo;

    while(atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}
