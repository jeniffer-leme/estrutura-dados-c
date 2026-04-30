#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numerosComplexos.h"

struct numerosComplexos {
    float real;
    float imaginario;
};

NumerosComplexos* criar(float x, float y) {
    NumerosComplexos* p = calloc(1, sizeof(NumerosComplexos));

    if(p == NULL) {
        printf("ERRO: Overflow!\n");
        return NULL;
    }

    p->real = x;
    p-> imaginario = y;

    return p;
}

void liberar(NumerosComplexos* p) {
    if(p != NULL) {
        free(p);
    }
}

void soma(NumerosComplexos* p, NumerosComplexos* q) {
    float realSoma = p->real + q->real;
    float imaginarioSoma = p->imaginario + q->imaginario;

    printf("NC1: %.2f + i%.2f\n", p->real, p->imaginario);
    printf("NC2: %.2f + i%.2f\n", q->real, q->imaginario);
    printf("Soma: %.2f + i%.2f\n", realSoma, imaginarioSoma);
}

void subtracao(NumerosComplexos* p, NumerosComplexos* q) {
    float realSub = p->real - q->real;
    float ImaginarioSub = p->imaginario - q->imaginario;

    printf("NC1: %.2f + i%.2f\n", p->real, p->imaginario);
    printf("NC2: %.2f + i%.2f\n", q->real, q->imaginario);
    printf("Subtração: %.2f + i%.2f\n", realSub, ImaginarioSub);
}

void multiplicacao(NumerosComplexos* p, NumerosComplexos* q) {
    float realMult = (p->real * q->real) - (p->imaginario * q->imaginario);
    float imaginarioMult = (p->real * q->imaginario) + (p->imaginario * q->real);

    printf("NC1: %.2f + i%.2f\n", p->real, p->imaginario);
    printf("NC2: %.2f + i%.2f\n", q->real, q->imaginario);
    printf("Multiplicação: %.2f + i%.2f\n", realMult, imaginarioMult);
}

void divisao(NumerosComplexos* p, NumerosComplexos* q) {
    float den = pow(q->real, 2) + pow(q->imaginario, 2);

    if(den == 0) {
        printf("ERRO: Não é possível dividir por zero.\n");
        return;
    }

    float realDiv = ((p->real * q->real) + (p->imaginario * q->imaginario)) / den;
    float imaginarioDiv = ((q->real * p->imaginario) - (p->real  * q->imaginario)) / den;

    printf("NC1: %.2f + i%.2f\n", p->real, p->imaginario);
    printf("NC2: %.2f + i%.2f\n", q->real, q->imaginario);
    printf("Divisão: %.2f + i%.2f\n", realDiv, imaginarioDiv);

}
