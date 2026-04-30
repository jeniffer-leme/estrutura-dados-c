#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

struct racionais {
    int denominador;
    int numerador;
};

Racionais* criarRacionais(int n, int d) {
    if (d == 0) {
        printf("ERRO: Denominador nao pode ser zero!\n");
        return NULL; 
    }
    
    Racionais* p = (Racionais*) calloc(1, sizeof(Racionais));  

    if(p == NULL) {
        printf("ERRO: Overflow!");
        return NULL;
    }

    p->numerador = n;
    p->denominador = d;

    return p;
}

void liberar(Racionais* p) {
    if(p != NULL) {
        free(p);
    }
}

void soma(Racionais* p, Racionais* q) {
    float soma = 0;

    int num = (p->numerador * q->denominador) + (p->denominador * q->numerador);
    int den = p->denominador * q->denominador;

    soma = (float)num / den;

    printf("Racional 1: %d/%d\n", p->numerador, p->denominador);
    printf("Racional 2: %d/%d\n", q->numerador, q->denominador);
    printf("Soma (decimal): %.2f\n", soma);
    printf("Soma (fração): %d/%d\n", num, den);
}

void multiplicacao(Racionais* p, Racionais* q) {
    float mult = 0;

    int num = p->numerador * q->numerador;
    int den = p->denominador * q->denominador;

    mult = (float)num / den;

    printf("Racional 1: %d/%d\n", p->numerador, p->denominador);
    printf("Racional 2: %d/%d\n", q->numerador, q->denominador);
    printf("Soma (decimal): %.2f\n", mult);
    printf("Soma (fração): %d/%d\n", num, den);
}

void testeIgualdade(Racionais* p, Racionais* q) {

    printf("\nRacional 1: %d/%d\n", p->numerador, p->denominador);
    printf("Racional 2: %d/%d\n", q->numerador, q->denominador);

    if(p->numerador == q->numerador && p->denominador == q->denominador) {
        printf("Igualdade: VERDADEIRO.\n");
    } else {
        printf("Igualdade: FALSO.\n");
    }
}
