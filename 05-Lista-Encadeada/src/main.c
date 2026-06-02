    #include <stdio.h>
    #include <stdlib.h>
    #include "listaEncadeada.h"


    int main() {
        int opcao;
        Lista *l1 = criarLista();
        Lista *l2 = criarLista();

        struct elemento valor;

        do {
            printf("\n=========MENU=========\n");
            printf("1. Inserir Ordenadamente na L1\n");
            printf("2. Inserir Ordenadamente na L2\n");
            printf("3. Remover Elemento na L1\n");
            printf("4. Remover Elemento na L2\n");
            printf("5. Impressão da Lista 1\n");
            printf("6. Impressão da Lista 2\n");
            printf("0. Sair\n");

            printf("\nDigite a opção desejada: ");
            scanf("%d", &opcao);

            switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor.num);

                if(inserirOrdenada(l1, valor)) {
                    printf("Inserido com sucesso na Lista 1!\n");
                } else {
                    printf("Número repetido ou erro na Lista 1!\n");
                }
                break;

            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor.num);

                if(inserirOrdenada(l2, valor)) {
                    printf("Inserido com sucesso na Lista 2!\n");
                } else {
                    printf("Número repetido ou erro na Lista 2!\n");
                }
                break;

            case 3:
            int num;

                printf("Digite o valor: ");
                scanf("%d", &num);

                if(removerElemento(l1, num)) {
                    printf("Removido com sucesso na Lista 1!\n");
                } else {
                    printf("Elemento não encontrado na Lista 1!\n");
                }
                break;

            case 4:
            int num2;

                printf("Digite o valor: ");
                scanf("%d", &num2);

                if(removerElemento(l2, num)) {
                    printf("Removido com sucesso na Lista 2!\n");
                } else {
                    printf("Elemento não encontrado na Lista 2!\n");
                }
                break;

            case 5:
                printf("\n=====IMPRESSAO DA LISTA 1=====\n");
                imprimirLista(l1);
                break;

            case 6:
                printf("\n=====IMPRESSAO DA LISTA 2=====\n");
                imprimirLista(l2);
                break;

            case 0:
                printf("Você saiu!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
            }

        }while (opcao != 0);


        return 0;
    }
