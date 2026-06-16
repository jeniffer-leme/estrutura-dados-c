#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

int main() {
    int opcao;
    int num;

    Lista* lista = criarLista();

    struct elemento retangulo;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir Retângulo\n");
        printf("2. Remover Retângulo\n");
        printf("3. Calcular Área\n");
        printf("4. Imprimir Retângulo\n");
        printf("0. Sair\n");

        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n=====INSERIR RETÂNGULO=====\n");

            printf("Digite o ID: ");
            scanf("%d", &retangulo.id);

            printf("Digite a base: ");
            scanf("%f", &retangulo.base);

            printf("Digite a altura: ");
            scanf("%f", &retangulo.altura);

            if(inserir(lista, retangulo)) {
                printf("Elemento inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir elemento!\n");
            }
            break;
        
        case 2:
            printf("\n=====REMOVER RETÂNGULO=====\n");

            printf("Digite o ID do retângulo: ");
            scanf("%d", &num);

            if(remover(lista, num)) {
                printf("Elemento removido com sucesso!\n");
            } else {
                printf("Erro ao remover elemento!\n");
            }
            break;
        
        case 3:
            printf("\n=====CALCULAR ÁREA DO RETÂNGULO=====\n");

            printf("Digite o ID do retângulo: ");
            scanf("%d", &retangulo.id);

            float area = calcularArea(lista, &retangulo);
            if(area > 0) {
                printf("Base(b): %.2f\n", retangulo.base);
                printf("Altura(h): %.2f\n", retangulo.altura);
                printf("Área: %.2f\n", area);
            } else {
                printf("Não foi possível calcular a área\n");
            }
            break;
        
        case 4:
            printf("\n=====IMPRIMIR RETÂNGULO=====\n");

            imprimir(lista);
            break;
        
        case 0:
            printf("Você saiu!\n");
            break;
            
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    }while(opcao != 0);

    apagarLista(lista);

    return 0;
}

