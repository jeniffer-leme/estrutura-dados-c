#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noPilha;

struct tipoPilha {
    struct tipoNo *inicio;
    int qtd;
};

Pilha *criarPilha() {
    Pilha *pilha = (Pilha *)calloc(1, sizeof(Pilha));

    if (pilha != NULL) {
        pilha->inicio = NULL;
        pilha->qtd = 0;
    }
    return pilha;
}

int push(Pilha *topo, struct elemento aluno) {
    if (topo == NULL)
    {
        return 0;
    }

    noPilha* no = (noPilha*) calloc(1, sizeof(noPilha));

    if(no == NULL) {
        return 0;
    }

    no->dado = aluno;

    no->prox = topo->inicio;
    topo->inicio = no;
    topo->qtd++;

    return 1;
}

int pop(Pilha* topo) {
    if(topo == NULL || topo->inicio == NULL) {
        return 0;
    }

    noPilha* aux = topo->inicio;

    topo->inicio = topo->inicio->prox;
    free(aux);

    topo->qtd--;

    return 1;
}

int consultaTopo(Pilha* topo, struct elemento *aluno) {
    if(topo == NULL || topo->inicio == NULL) {
        return 0;
    }

    *aluno = topo->inicio->dado;

    return 1;
}

int tamanhoPilha(Pilha* topo) {
    if(topo ==  NULL) {
        return 0;
    }

    return topo->qtd;
}

int pilhaVazia(Pilha* topo) {
    if(topo == NULL) {
        return 0;
    }

    if(topo->inicio == NULL) {
        return 1;
    }

    return 0;
}

void imprimePilha(Pilha* topo) {
    if(topo == NULL || topo->inicio == NULL) {
        return;
    }

    noPilha* atual = topo->inicio;

    while(atual != NULL) {
        printf("Matricula: %d\n", atual->dado.matricula);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Nota 1: %.2f\n", atual->dado.nota1);
        printf("Nota 2: %.2f\n", atual->dado.nota2);

        printf("------------------------------------\n");

        atual = atual->prox;
    }
}

void apagaPilha(Pilha* topo) {
    if(topo != NULL) {
        
        while(topo->inicio != NULL) {
            noPilha* aux = topo->inicio;

            topo->inicio = topo->inicio->prox;
            free(aux);
        }       
        free(topo);
    }
}
