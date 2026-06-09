#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main () {
    int opcao;

    Fila* fila  = criarFila();
    struct elemento aluno;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir na Fila\n");
        printf("2. Remover da Fila\n");
        printf("3. Consultar Fila\n");
        printf("4. Tamanho da Fila\n");
        printf("5. Fila Vazia\n");
        printf("6. Imprime Fila\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n=====INSERIR NA FILA=====\n");

            printf("Digite a matricula: ");
            scanf("%d", &aluno.matricula);

            printf("Digite o nome: ");
            scanf("%s", aluno.nome); 

            printf("Digite a nota 1: ");
            scanf("%f", &aluno.nota1);

            printf("Digite a nota 2: ");
            scanf("%f", &aluno.nota2);

            if(insereFila(fila, aluno)) {
                printf("Inserção na fila ocorreu com sucesso!\n");
            } else {
                printf("Erro ao inserir na fila\n");
            }
            break;

        case 2:
            printf("\n====REMOVER FILA====\n");

            if(removeFila(fila)) {
                printf("Elemento removido da fila com sucesso!\n");
            } else {
                printf("Erro ao remover elemento da fila! Fila vazia ou inexistente.\n");
            }
            break;

        case 3:
            printf("\n====CONSULTAR FILA====\n");

            if(consultaFila(fila, &aluno)) {
                printf("\nAluno Encontrado:\n");
                printf("Matrícula: %d\n", aluno.matricula);
                printf("Nome: %s \n", aluno.nome);
                printf("Nota 1: %.2f\n", aluno.nota1);
                printf("Nota 2: %.2f\n", aluno.nota2);
            } else {
                printf("Erro na consulta! Fila vazia ou inexistente\n");
            }
            break;

        case 4:
            printf("\n========TAMANHO========\n");

            printf("Tamanho da Lista: %d\n", tamanhoFila(fila));
            break;

        case 5:
            printf("\n========FILA VAZIA========\n");

            if(filaVazia(fila)) {
                printf("A fila está vazia.\n");
            } else {
                printf("A fila não está vazia.\n");
            }
            break;

        case 6:
            printf("\n========IMPRESSÃO DA FILA========\n");

            imprimeFila(fila);
            break;

        case 0:
            printf("Você saiu!\n");
        break;
        
        default:
            printf("Opção Inválida! Tente novamente.\n");
            break;
        }
    }while(opcao != 0);

    liberaFila(fila);
}
