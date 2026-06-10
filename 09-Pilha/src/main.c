#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int opcao;

    Pilha* topo = criarPilha();
    struct elemento aluno;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir na Pilha\n");
        printf("2. Remover da Pilha\n");
        printf("3. Consultar Pilha\n");
        printf("4. Tamanho da Pilha\n");
        printf("5. Pilha Vazia\n");
        printf("6. Imprime Pilha\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n=====INSERIR NA PILHA=====\n");

            printf("Digite a matricula: ");
            scanf("%d", &aluno.matricula);

            printf("Digite o nome: ");
            scanf("%s", aluno.nome); 

            printf("Digite a nota 1: ");
            scanf("%f", &aluno.nota1);

            printf("Digite a nota 2: ");
            scanf("%f", &aluno.nota2);

            if(push(topo, aluno)) {
                printf("Aluno inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir o aluno. Pilha inexistente!\n");
            }
            break;
        
        case 2:
            printf("\n=====REMOVER DA PILHA=====\n");

            if(pop(topo)) {
                printf("Aluno removido com sucesso!\n");
            } else {
                printf("Erro ao remover aluno. Pilha inexistente ou vazia!\n");
            }
            break;
        
        case 3:
            printf("\n====CONSULTAR PILHA====\n");

            if(consultaTopo(topo, &aluno)) {
                printf("\nAluno Encontrado:\n");
                printf("Matrícula: %d\n", aluno.matricula);
                printf("Nome: %s \n", aluno.nome);
                printf("Nota 1: %.2f\n", aluno.nota1);
                printf("Nota 2: %.2f\n", aluno.nota2);
            } else {
                printf("Erro ao consultar pilha. Pilha vazia ou inexistente!\n");
            }
            break;
        
        case 4:
            printf("\n=====TAMANHO=====\n");

            printf("Tamanho: %d\n", tamanhoPilha(topo));
            break;
        
        case 5:
            printf("\n=====PILHA VAZIA=====\n");
            
            if(pilhaVazia(topo)) {
            printf("A pilha está vazia!\n");
            } else {
                printf("A pilha não está vazia!\n");
            }
            break;
        
        case 6:
            printf("\n=====IMPRIMIR PILHA=====\n");

            imprimePilha(topo);
            break;
        
        case 0:
            printf("VocÊ saiu!\n");
            break;
            
        default:
        printf("Opção inválida! Tente Novamente.\n");
            break;
        }


    }while(opcao != 0);

    apagaPilha(topo);

    return 0;
}
