#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

int main() {
    int opcao;
    int num;

    Lista* L1 = criarLista();
    Lista* L2 = criarLista();
    Lista* L3 = NULL;

    struct elemento aluno;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir Ordenado L1\n");
        printf("2. Inserir Ordenado L2\n");
        printf("3. Remover da Lista 1\n");
        printf("4. Remover da Lista 2\n");
        printf("5. Imprimir Lista 1\n");
        printf("6. Imprimir Lista 2\n");
        printf("7. Merge Lista\n");
        printf("0. Sair\n");

        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n=====INSERIR NA LISTA 1=====\n");
            printf("Digite um número: ");
            scanf("%d", &aluno.numeros);

            if(inserirOrdenado(L1, aluno)) {
                printf("Elemento inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir elemento!\n");
            }
            break;
        
        case 2:
            printf("\n=====INSERIR NA LISTA 2=====\n");
            printf("Digite um número: ");
            scanf("%d", &aluno.numeros);

            if(inserirOrdenado(L2, aluno)) {
                printf("Elemento inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir elemento!\n");
            }
            break;
        
        case 3:
            printf("\n=====REMOVER DA LISTA 1=====\n");
            printf("Digite o valor que deseja remover: ");
            scanf("%d", &num);

            if(removerElemento(L1, num)) {
                printf("Elemento removido com sucesso!\n");
            } else {
                printf("Erro ao remover elemento!\n");
            }
            break;
        
        case 4:
            printf("\n=====REMOVER DA LISTA 2=====\n");
            printf("Digite o valor que deseja remover: ");
            scanf("%d", &num);

            if(removerElemento(L2, num)) {
                printf("Elemento removido com sucesso!\n");
            } else {
                printf("Erro ao remover elemento!\n");
            }
            break;
        
        case 5:
            printf("\n=====IMPRIMIR LISTA 1=====\n");

            imprimirLista(L1);
            break;
        
        case 6:
            printf("\n=====IMPRIMIR LISTA 2=====\n");

            imprimirLista(L2);
            break;
        
        case 7:
            printf("\n=====MERGE DAS LISTAS=====\n");

            if(L3 != NULL) {
                liberarLista(L3);
            }

            L3 = mergeListas(L1, L2);
            imprimirLista(L3);
            break;
            
        case 0:
            printf("Você saiu!\n");
            break;
            
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    }while(opcao != 0);

    liberarLista(L1);
    liberarLista(L2);
    liberarLista(L3);

    return 0;
}
