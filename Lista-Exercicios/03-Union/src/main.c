#include <stdio.h>
#include <stdlib.h>
#include "union.h"

int main() {
    int opcao;
    int num;

    Lista* L1 = criarLista();
    Lista* L2 = criarLista();
    Lista* L3 = NULL;

    struct elemento valor;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir Elemento na L1\n");
        printf("2. Inserir Elemento na L2\n");
        printf("3. Remover Elemento na L1\n");
        printf("4. Remover Elemento na L2\n");
        printf("5. Impressão da Lista 1\n");
        printf("6. Impressão da Lista 2\n");
        printf("7. União das Listas\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n-------INSERÇÃO NA LISTA 1-------\n");

            printf("Digite um valor: ");
            scanf("%d", &valor.numeros);

            if(insereElemento(L1, valor)){
                printf("Valor inserido com sucesso na Lista 1!\n");
            } else {
                printf("Erro ao inserir elemento na Lista 1! Lista inexistente.\n");
            }
            break;
        
        case 2:
            printf("\n-------INSERÇÃO NA LISTA 2-------\n");

            printf("Digite um valor: ");
            scanf("%d", &valor.numeros);

            if(insereElemento(L2, valor)){
                printf("Valor inserido com sucesso na Lista 2!\n");
            } else {
                printf("Erro ao inserir elemento na Lista 2! Lista inexistente.\n");
            }
            break;
        
        case 3:
            printf("\n-------REMOÇÃO NA LISTA 1-------\n");

            printf("Digite o valor que deseja remover: ");
            scanf("%d", &num);

            if(removeElemento(L1, num)) {
                printf("Elemento %d removido com sucesso na Lista 1\n", num);
            } else {
                printf("Erro ao remover o elemento %d da Lista 1\n", num);
            }
            break;
        
        case 4:
            printf("\n-------REMOÇÃO NA LISTA 2-------\n");

            printf("Digite o valor que deseja remover: ");
            scanf("%d", &num);

            if(removeElemento(L2, num)) {
                printf("Elemento %d removido com sucesso na Lista 2\n", num);
            } else {
                printf("Erro ao remover o elemento %d da Lista 2\n", num);
            }
            break;
        
        case 5:
            printf("\n-------IMPRIMIR LISTA 1-------\n");

            imprimeLista(L1);
            break;
        
        case 6:
            printf("\n-------IMPRIMIR LISTA 2-------\n");

            imprimeLista(L2);
            break;
        
        case 7:
            printf("\n-------UNIÃO DAS LISTAS-------\n");

            if(L3 == NULL) {
                apagaLista(L3);
            }

            L3 = uniaoListas(L1, L2);
            imprimeLista(L3);
            break;
        
        case 0:
            printf("Você saiu!\n");
            break;
            
        default:
            break;
        }

    }while(opcao != 0);

    apagaLista(L1);
    apagaLista(L2);
    apagaLista(L3);

    return 0;
}
