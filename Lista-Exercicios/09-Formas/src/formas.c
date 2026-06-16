#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "formas.h"

struct tipoNo {
    struct elementos dado;
    struct tipoNo* prox;
};

struct tipoLista {
    struct tipoNo* inicio;
    int qtd;
};

typedef struct tipoNo noLista;

Lista* criarLista() {
    Lista* list = (Lista*) calloc(1, sizeof(Lista));

    if(list != 0) {
        list->inicio = NULL;
        list->qtd = 0;
    }
    return list;
}

int inserirForma(Lista* lista, struct elementos forma) {
    if(lista == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = forma;

    no->prox = lista->inicio;
    lista->inicio = no;

    lista->qtd++;
    return 1;
}

int removerForma(Lista* lista, int id) {
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

float calcularArea(Lista* lista, int id) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio;

    while(atual != NULL && atual->dado.id != id) {
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    switch (atual->dado.formas) {
    case RETANGULO:
        return atual->dado.figura.ret.base * atual->dado.figura.ret.altura;
        
    case TRIANGULO:
        return (atual->dado.figura.tri.base * atual->dado.figura.tri.altura) / 2.0;
    
    case CIRCULO:
        return 3.14 * pow(atual->dado.figura.circ.raio, 2);

        default:
            return 0;
    }

}

void imprimir(Lista* lista) {
    if(lista == NULL || lista->inicio == NULL) {
        return;
    }

    noLista* atual = lista->inicio;

    while(atual != NULL) {
        printf("ID: %d", atual->dado.id);

        switch (atual->dado.formas) {
        case RETANGULO:
            printf("------TIPO RETANGULO------\n");
            printf("Base(b): %.2f\n", atual->dado.figura.ret.base);
            printf("Altura(h): %.2f\n", atual->dado.figura.ret.altura);
            break;
        
        case TRIANGULO:
            printf("------TIPO TRIANGULO------\n");
            printf("Base(b): %.2f\n", atual->dado.figura.tri.base);
            printf("Altura(h): %.2f\n", atual->dado.figura.tri.altura);
            break;

        case CIRCULO:
            printf("------TIPO CIRCULO------\n");
            printf("Raio(r): %.2f\n", atual->dado.figura.circ.raio);
            break;
        }

        printf("--------------------------------\n");

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
