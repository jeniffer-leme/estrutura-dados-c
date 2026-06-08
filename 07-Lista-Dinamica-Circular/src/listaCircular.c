#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

typedef struct tipoNo noLista;

Lista* criarLista(Lista* inicio) {
    Lista* list = (Lista*) calloc(1, sizeof(noLista));

    if(list != NULL) {
        *list = NULL;
    }

    return list;    
}

int insereInicio(Lista* inicio, struct elemento aluno) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    noLista* atual;

    no->dado = aluno;
    atual = *inicio;

    if(*inicio == NULL) {
        *inicio = no;
        no->prox = no;

        return 1;
    } 

    while(atual->prox != *inicio) {
        atual = atual->prox;
    }

    atual->prox = no;
    no->prox = *inicio;
    *inicio = no;


    return 1;    
}

int insereFinal(Lista* inicio, struct elemento aluno) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    noLista *atual;

    if(no == NULL) {
        return 0;
    }

    no->dado = aluno;
    atual = *inicio;

    if(*inicio == NULL) {
        *inicio = no;
        no->prox = *inicio;

        return 1;
    }

    while(atual->prox != *inicio) {
        atual = atual->prox;
    }

    atual->prox = no;
    no->prox = *inicio;

    return 1;
}

int insereOrdenado(Lista* inicio, struct elemento aluno) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }            

    no->dado = aluno;

    if(*inicio == NULL) {
        *inicio = no;
        no->prox = *inicio;

        return 1;
    }  


    if((*inicio)->dado.matricula > aluno.matricula) {
        noLista* aux = *inicio;

        while(aux->prox != *inicio) {
            aux = aux->prox;    
        }

        aux->prox = no;
        no->prox = *inicio;
        *inicio = no;

        return 1;
    } 

    noLista* anterior = (*inicio), *atual = (*inicio)->prox;

    while(atual != *inicio && atual->dado.matricula < aluno.matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    no->prox = atual;   
    anterior->prox = no;
    

    return 1;
}

//TERMINAR
int removeMatricula(Lista* inicio, int matricula) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    noLista* anterior = *inicio, *atual = (*inicio)->prox;

    while(atual != NULL && atual->dado.matricula < matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    


}

int tamanhoLista(Lista* inicio) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    noLista* atual = *inicio;
    int cont = 0;

    do {
        cont++;
        atual = atual->prox;
    }while(atual != *inicio);

    return 1;
}

int listaVazia(Lista* inicio) {
    if(inicio == NULL) {
        return 0;
    }

    if(*inicio == NULL) {
        return 1;
    }

    return 0;
}

void apagaLista(Lista* inicio) {
    if(inicio != NULL) {
        noLista* atual;

        while(*inicio != NULL) {
            atual = *inicio;
            atual = atual->prox;
            free(atual);
        }
        free(inicio);
    }
}
