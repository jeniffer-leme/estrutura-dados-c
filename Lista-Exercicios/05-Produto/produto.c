#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

struct tipoNo {
    struct elemento dado;
    struct tipoNo* prox;
};

struct tipoLista {
    struct tipoNo* inicio;
    int qtd;
};

typedef struct tipoNo noLista;

Lista* criarLista() {
    Lista* list = (Lista*) calloc(1, sizeof(Lista));

    if(list != NULL) {
        list->inicio = NULL;
        list->qtd = 0;
    }

    return list;
}

int cadastrarProduto(Lista* lista, struct elemento produto) {
    if(lista == NULL) {
        return 0;
    }

    noLista* no = (noLista*) calloc(1, sizeof(noLista));

    if(no == NULL) {
        return 0;
    }

    no->dado = produto;

    no->prox = lista->inicio;
    lista->inicio = no;
    lista->qtd++;

    return 1;
}

int apagarProduto(Lista* lista, int codigo) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio, *ant = NULL;

    while(atual != NULL && atual->dado.codigo != codigo) {
        ant = atual;
        atual = atual->prox;
    };

    if(atual == NULL) {
        return 0;
    }

    if(atual == lista->inicio) {
        lista->inicio = lista->inicio->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    lista->qtd--;

    return 1;
}

int atualizarCadastro(Lista* lista, int codigo, struct elemento produto) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio;

    while(atual != NULL && atual->dado.codigo != codigo) {
        atual = atual->prox;
    }

    if(atual == NULL) {
        return 0;
    }

    printf("Nome: ");
    scanf("%s", &atual->dado.nome);

    printf("Preço: ");
    scanf("%f", &atual->dado.preco);

    printf("Quantidade: ");
    scanf("%d", &atual->dado.quantidade);

    printf("Data: ");
    scanf("%d", &atual->dado.data);

    return 1;
}

int buscarMenorPreco(Lista* lista, struct elemento produto) {
    if(lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    noLista* atual = lista->inicio;

    atual->dado = produto;

    while(atual != NULL && atual->dado.preco > produto.preco) {
        atual = atual->prox;
    }

    
}
