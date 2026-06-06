#include <stdio.h>
#include <stdlib.h>
#include "duplamenteEncadeada.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
    struct tipoNo* ant;
};

typedef struct tipoNo noLista;

Lista* criarLista() {
    Lista* list = calloc(1, sizeof(Lista));

    if(list != NULL) {
        *list = NULL;
    }

    return list;
}

int insereFinal(Lista* inicio, struct elemento aluno) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = aluno;
    no->prox = NULL;
    
    if((*inicio) == NULL) {
        no->ant = NULL;
        *inicio = no;
    } else{
        noLista* aux = *inicio;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = no;
        no->ant = aux;
    }

    return 1;
}

int insereInicio(Lista* inicio, struct elemento aluno) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = aluno;
    no->prox = *inicio;
    no->ant = NULL;

    if(*inicio != NULL) {
        (*inicio)->ant = no;
    }

    *inicio = no;

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
        no->prox = NULL;
        no->ant = NULL;
        *inicio = no;

        return 1;
    } else {
        noLista *anterior = NULL, *atual = *inicio;

        while(atual != NULL && atual->dado.matricula < aluno.matricula) {
            anterior = atual;
            atual = atual->prox;
        }

        if(atual == *inicio) {
            no->ant = NULL;
            (*inicio)->ant = no;
            no->prox = *inicio;
            *inicio = no;
        } else {
            no->prox = anterior->prox;
            no->ant = anterior;     
            anterior->prox = no;    
            
            if(atual != NULL) {
                atual->ant = no;
            }
        }

        return 1;
    }
}

int removeMatricula(Lista* inicio, int matricula) {
    if(inicio == NULL) {
        return 0;
    }

    noLista* anterior = NULL, *atual = *inicio;

    while(atual != NULL && atual->dado.matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    if(atual == *inicio) {
        *inicio = atual->prox;

        if(*inicio != NULL) {
            (*inicio)->ant = NULL;
        }
    } else {
        anterior->prox = atual->prox;

        if(atual->prox != NULL) {
            atual->prox->ant = anterior;
        }
    }

    free(atual);
    return 1;
}

int removeInicio(Lista* inicio) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    noLista* atual = *inicio;

    *inicio = atual->prox;
    
    if(*inicio != NULL) {
        (*inicio)->ant = NULL;
    }

    free(atual);
    return 1;
}

int tamanhoLista(Lista* inicio) {
    if(inicio == NULL) {
        return 0;
    }

    int cont = 0;
    noLista* atual = *inicio;

    while(atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

int listaVazia(Lista* inicio) {
    if(inicio == NULL){
        return 1;
    }

    if(*inicio == NULL) {
        return 1;
    }

    return 0;
}

int listaCheia(Lista* inicio) {
    return 0;
}

void imprimeLista(Lista* inicio) {
    if(inicio == NULL || *inicio == NULL) {
        return;
    }

    noLista* atual = *inicio;

    while(atual != NULL) {
        printf("Matricula: %d\n", atual->dado.matricula);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Nota 1: %.2f\n", atual->dado.nota1);
        printf("Nota 2: %.2f\n", atual->dado.nota2);
        printf("Nota 3: %.2f\n", atual->dado.nota3);

        printf("------------------------------------\n");
        atual = atual->prox;
    }
}

int consultaMatricula(Lista* inicio, int matricula, struct elemento *aluno) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    noLista* atual = *inicio;

    while(atual != NULL && atual->dado.matricula != matricula) {
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    *aluno = atual->dado;
    return 1;
}

int consultaPosicao(Lista* inicio, int posicao, struct elemento* aluno) {
    if(inicio == NULL || *inicio == NULL) {
        return 0;
    }

    noLista* atual = *inicio;

    int i = 1;

    while(atual != NULL && i < posicao) {
        atual = atual->prox;
        i++;
    }

    if(atual == NULL) {
        return 0;
    }

    *aluno = atual->dado;

    return 1;
}

void apagaLista(Lista* inicio) {
    if(inicio != NULL) {
        noLista* atual;

        while(*inicio != NULL) {
            atual = *inicio;
            *inicio = (*inicio)->prox;
            free(atual);
        }
        free(inicio);
    }
}
