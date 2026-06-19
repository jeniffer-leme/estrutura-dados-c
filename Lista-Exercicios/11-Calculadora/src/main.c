#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main() {
    int opcao;
    int operacao;

    Lista* L1 = criarLista();

    struct elemento valor, num1, num2, resultado;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir Valro\n");
        printf("2. Operação\n");
        printf("3. Resultado\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n=====INSERIR VALOR=====\n");

            printf("Digite um valor: ");
            scanf("%f", &valor.numero);

            if(inserirFinal(L1, valor)) {
                printf("Valor inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir o valor!\n");
            }
            break;
        
        case 2:
            printf("\n=====OPERAÇÕES=====\n");

            if(tamanhoLista(L1) < 2) {
                printf("É necessário, no mínimo, 2 números!\n");
                break;
            }

            printf("1. Soma\n");
            printf("2. Subtrção\n");
            printf("3. Multiplicação\n");
            printf("4. Divisão\n");

            printf("\nDigite a operação que deseja: ");
            scanf("%d", &operacao);

            removerFinal(L1, &num2);
            removerFinal(L1, &num1);

            resultado.numero = 0;

            switch (operacao) {
            case 1:
                resultado.numero = somar(num1.numero, num2.numero);
                printf("Calculo: %.2f + %.2f\n", num1.numero, num2.numero);
                inserirFinal(L1, resultado);
                break;
            
            case 2:
                resultado.numero = subtrair(num1.numero, num2.numero);
                printf("Calculo: %.2f - %.2f\n", num1.numero, num2.numero);
                inserirFinal(L1, resultado);
                break;
            
            case 3:
                resultado.numero = multiplicar(num1.numero, num2.numero);
                printf("Calculo: %.2f x %.2f\n", num1.numero, num2.numero);
                inserirFinal(L1, resultado);
                break;
            
            case 4:
                if(num2.numero == 0) {
                    printf("Não é possível dividir por zero!\n");
                    inserirFinal(L1, num1);
                    inserirFinal(L1, num2);
                } else {
                    resultado.numero = dividir(num1.numero, num2.numero);
                    printf("Calculo: %.2f / %.2f\n", num1.numero, num2.numero);
                    inserirFinal(L1, resultado);
                }
                break;

                default:
                    printf("Operação inválida!\n");
                    inserirFinal(L1, num1);
                    inserirFinal(L1, num2);
                break;
            }
        break;
            
        case 3:
            if(listaVazia(L1)){
                printf("A lista está vazia!\n");
            } else if(tamanhoLista(L1) > 1){
                printf("Faltam números para serem calculados!\n");
            } else {
                removerFinal(L1, &valor);
                printf("RESULTADO FINAL: %.2f\n", valor.numero);
            }
            break;
        
        case 0:
            printf("Você saiu!\n");
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
        }

    }while(opcao != 0);

    liberarLista(L1);

    return 0;
}
