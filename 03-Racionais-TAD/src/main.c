#include <stdio.h>
#include "racional.h"

int main() {
    Racionais *p = NULL, *q = NULL;
    int num, den;
    int opcao;

    do {
        printf("\n=========MENU=========\n");
        printf("1. Criar Racionais\n");
        printf("2. Soma\n");
        printf("3. Multiplicação\n");
        printf("4. Teste Igualdade\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if(opcao >= 2 && opcao <= 4 && (p == NULL || q == NULL)) {
            printf("ERRO: Primeiro crie valores na opção 1.\n");
            continue;
        }

        switch (opcao) {
        case 1:
            printf("\nDigite o numerador: ");
            scanf("%d", &num);
            
            printf("Digite o denominador: ");
            scanf("%d", &den);

            p = criarRacionais(num, den);


            printf("Digite o numerador: ");
            scanf("%d", &num);
            
            printf("Digite o denominador: ");
            scanf("%d", &den);

            q = criarRacionais(num, den);
            break;

        case 2:
            printf("\n---------SOMA--------\n");
            soma(p, q);
            break;

        case 3:
            printf("\n-------MULTIPLICAÇÃO------\n");
            multiplicacao(p, q);
            break;

        case 4:
            testeIgualdade(p, q);
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
