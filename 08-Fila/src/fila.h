#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

struct tipoFila {
    struct tipoNo* inicio;
    struct tipoNo* fim;
    int qtd;
};

typedef struct tipoNo noLista;

Fila* criarFila() {
    Fila* fila = (Fila*) calloc(1, sizeof(Fila));
    if(fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->qtd = 0;
    }

    return fila;
}

int insereFila(Fila* fila, struct elemento aluno) {
    if(fila == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    no->dado = aluno;
    no->prox = NULL;

    if(fila->fim == NULL) {
        fila->inicio = no;
    } else {
        fila->fim->prox = no;
    }
    fila->fim = no;
    fila->qtd++;

    return 1;
}

int removeFila(Fila* fila) {
    if(fila == NULL || fila->inicio == NULL) {
        return 0;
    }

    noLista* no = fila->inicio;

    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(no);
    fila->qtd--;

    return 1;
}

int consultaFila(Fila* fila, struct elemento *aluno) {
    if(fila == NULL || fila->inicio == NULL) {
        return 0;
    }

    *aluno = fila->inicio->dado;

    return 1;
}

int tamanhoFila(Fila* fila) {
    if(fila == NULL || fila->inicio == NULL) {
        return 0;
    }

    return fila->qtd;
}

int filaVazia(Fila* fila) {
    if(fila == NULL) {
        return 0;
    }

    if(fila->fim == NULL) {
        return 1;
    } 

    return 0;
}

void imprimeFila(Fila* fila) {
    if(fila == NULL || fila->inicio == NULL) {
        return;
    }

    noLista* atual = fila->inicio;

    while (atual != NULL) {
        printf("Matricula: %d\n", atual->dado.matricula);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Nota 1: %.2f\n", atual->dado.nota1);
        printf("Nota 2: %.2f\n", atual->dado.nota2);

        printf("---------------------------------\n");

        atual = atual->prox;
    }
}

void liberaFila(Fila* fila) {
    if(fila != NULL) {
        noLista* atual = fila->inicio;

        while (fila->inicio != NULL) {
            fila->inicio = fila->inicio->prox;
            free(atual);
        }
        free(fila); 
    }
}
