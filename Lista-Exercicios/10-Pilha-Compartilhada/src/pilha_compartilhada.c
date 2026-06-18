#include <stdio.h>
#include <stdlib.h>
#include "pilha_compartilhada.h"

struct tipoPilha {
    struct elemento vetor[NUM]; 
    int topo1;                
    int topo2;                
};

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*) calloc(1, sizeof(Pilha));

    if(pilha != NULL) {
        pilha->topo1 = -1;
        pilha->topo2 = NUM;
    }
    return pilha;
}

int push(Pilha* pilha, struct elemento valor, int num) {
    if(pilha == NULL) {
        return 0;
    }

    if(pilha->topo1 + 1 == pilha->topo2) {
        return 0;
    }

    if(num == 1) {
        pilha->topo1++;
        pilha->vetor[pilha->topo1] = valor;
    } else if(num == 2) {
        pilha->topo2--;
        pilha->vetor[pilha->topo2] = valor;
    }

    return 1;
}

int pop(Pilha* pilha, struct elemento* valor, int num) {
    if(pilha == NULL) {
        return 0;
    }

    if(num == 1 && pilha->topo1 != -1) {
        *valor = pilha->vetor[pilha->topo1];
        pilha->topo1--;
        return 1;
    }

    if(num == 2 && pilha->topo2 != NUM) {
        *valor = pilha->vetor[pilha->topo2];
        pilha->topo2++;
        return 1;
    }
    
    return 0;
}

int pilhaVazia(Pilha* pilha, int num) {
    if(pilha == NULL) {
        return 1;
    }

    if(num == 1 && pilha->topo1 == -1) {
        return 1;
    }

    if(num == 2 && pilha->topo2 == NUM) {
        return 1;
    }

    return 0;
}

int pilhaCheia(Pilha* pilha) {
    if(pilha == NULL) {
        return 0;
    }

    return pilha->topo1 + 1 == pilha->topo2;
}

void imprimirPilha(Pilha* pilha, int num) {
    if(pilha == NULL) {
        return;
    }

    if(num == 1) {
        if(pilha->topo1 == -1) {
            printf("Pilha 1 vazia!\n");
        } else {
            printf("Elementos da Pilha 1 (topo a base)\n");

            for(int i = pilha->topo1; i >= 0; i--) {
                printf("Valor: %d\n", pilha->vetor[i].chave);
            }
        }
    }

    if(num == 2) {
        if(pilha->topo2 == NUM) {
            printf("Pilha vazia!\n");
        } else {
            printf("Elementos da Pilha 2 (topo a base)\n");

            for(int i = pilha->topo2; i < NUM; i++) {
                printf("Valor: %d\n", pilha->vetor[i].chave);
            }
        }
    }
    return;
}

void liberarPilha(Pilha* pilha) {
    if(pilha != NULL) {
        free(pilha);
    }
}
