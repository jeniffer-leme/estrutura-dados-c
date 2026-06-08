#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

typedef struct tipoNo noLista;

Lista* criarLista() {
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

    if(no == NULL) {
        return 0;
    }

    noLista *atual;

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

int removeMatricula(Lista* inicio, int matricula) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    if((*inicio)->dado.matricula == matricula) {

        if((*inicio)->prox == *inicio) {
            free(*inicio);
            *inicio = NULL;

            return 1;

        } else {
        noLista* aux = *inicio;
        noLista* atual = *inicio;

        while(aux->prox != *inicio) {
            aux = aux->prox;
        }

        aux->prox = (*inicio)->prox;
        *inicio = (*inicio)->prox;
        free(atual);

        return 1;
        }
    }

    noLista* anterior = *inicio, *atual = (*inicio)->prox;

    while(atual != *inicio && atual->dado.matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == *inicio ) {
        return 0;
    }

    anterior->prox = atual->prox;
    free(atual);

    return 1;
}

int removeInicio(Lista* inicio) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    if((*inicio)->prox == (*inicio)) {
        free(*inicio);
        *inicio = NULL;

        return 1;
    }

    noLista* atual = *inicio;

    while (atual->prox != *inicio) {
        atual = atual->prox;
    }

    noLista* aux = *inicio;

    atual->prox = (*inicio)->prox;
    *inicio = (*inicio)->prox;

    free(aux);    
    return 1;
}

int removeFinal(Lista* inicio) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    if((*inicio)->prox == *inicio) {
        free(*inicio);
        *inicio = NULL;

        return 1;
    }

    noLista* anterior = *inicio, *atual = (*inicio)->prox;

    while (atual->prox != *inicio) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = *inicio;

    free(atual);
    return 1;
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

    return cont;
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

void imprimeLista(Lista* inicio) {
    if(inicio == NULL || *inicio == NULL) {
        return;
    }

    noLista* atual = *inicio;

    do {
        printf("Matrícula: %d\n", atual->dado.matricula);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Nota 1: %.2f\n", atual->dado.nota1);
        printf("Nota 2: %.2f\n", atual->dado.nota2);

        printf("------------------------------------------\n");

        atual = atual->prox;
    }while(atual != *inicio);
}

void apagaLista(Lista* inicio) {
    if(inicio != NULL && *inicio != NULL) {

        noLista* atual = *inicio, *aux;

        while(atual->prox != *inicio) {
            atual = atual->prox;
        }

        atual->prox = NULL; 
        
        atual = *inicio;
        
        while(atual != NULL) {
            aux = atual->prox; 
            free(atual);       
            atual = aux;       
        }

        *inicio = NULL; 
    }

    free(inicio); 
}
