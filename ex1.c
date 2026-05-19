#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int prox;
    int ordem[MAX];
}Lista;

int ordenado(Lista* p) {

    if(p == NULL) {
        printf("ERRO: Overflow!\n");
        return 0;
    }

    for(int i = 0; i < p->prox - 1; i++) {
        if(p->ordem[i] > p->ordem[i + 1]) {
           return 0; 
        } 
    }

    return 1;
}

int main() {
    Lista p;

    printf("digite 5 números inteiros: ");
    for(int i = 0; i < MAX; i++) {
        scanf("%d", &p.ordem[i]);
    }
    p.prox = MAX;

    if(ordenado(&p) == 1) {
        printf("A lista está ordenada.\n");
    } else {
        printf("A lista não está ordenada.\n");
    }

    return 0;
}
