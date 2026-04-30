#include <stdio.h>
#include "numerosComplexo.h"

int main() {
    NumerosComplexos *p = NULL, *q= NULL;
    float x, y;
    int opcao;

    do {
        printf("\n=========MENU=========\n");
        printf("1. Números Complexos\n");
        printf("2. Soma\n");
        printf("3. Subtração\n");
        printf("4. Multiplicação\n");
        printf("5. Divisão\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if(opcao >= 2 && opcao <= 5 && (p == NULL || q == NULL)) {
            printf("ERRO: Inicie os valores na opção 1.\n");
            continue;
        }

        switch (opcao) {
        case 1:
            printf("\nDigite o numero real: ");
            scanf("%f", &x);
            
            printf("Digite o o numero imaginario: ");
            scanf("%f", &y);

            p = criar(x, y);


            printf("Digite o numerador: ");
            scanf("%f", &x);
            
            printf("Digite o denominador: ");
            scanf("%f", &y);

            q = criar(x, y);
            break;

        case 2:
            printf("\n---------SOMA--------\n");
            soma(p, q);
            break;

        case 3:
            printf("\n-------SUBTRAÇÃO------\n");
            subtracao(p, q);
            break;

        case 4:
            printf("\n-------MULTIPLICAÇÃO------\n");
            multiplicacao(p, q);
            break;

        case 5:
             printf("\n-------DIVISÃO------\n");
            divisao(p, q);
            break;

        case 0:
            printf("Você saiu!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    }while (opcao != 0);

    liberar(p);
    liberar(q);


    return 0;
}
