#include <stdio.h>
#include <stdlib.h>
#include "invertido.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

struct tipoPilha {
    struct tipoNo* topo;
    int qtd;
};

typedef struct tipoNo noPilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*) calloc(1, sizeof(Pilha));

    if(pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}

int empilhar(Pilha* pilha, struct elemento valor) {
    if(pilha == NULL) {
        return 0;
    }

    noPilha* no = (noPilha*) calloc(1, sizeof(noPilha));

    if(no == NULL) {
        return 0;
    }

    no->dado = valor;

    no->prox = pilha->topo;
    pilha->topo = no;

    pilha->qtd++;
    return 1;
}

int pilhaVazia(Pilha* pilha) {
    if(pilha == NULL || pilha->topo == NULL) {
        return 1;
    }
    return 0;
}

int desempilhar(Pilha* pilha, struct elemento* valor) {
    if(pilha == NULL || pilhaVazia(pilha)) {
        return 0;
    }

    noPilha* no = pilha->topo;
    *valor = no->dado;
    
    pilha->topo = no->prox;
    free(no);
    
    pilha->qtd--;
    return 1;
}

void liberarPilha(Pilha* pilha) {
    if(pilha != NULL) {
        struct elemento lixo;
        while(!pilhaVazia(pilha)) {
            desempilhar(pilha, &lixo);
        }
        free(pilha);
    }
}
