#include <stdio.h>
#include <stdlib.h>
#include "duplamenteEncadeada.h"

int main() {
    int matricula, posicao;
    int opcao;
    Lista* inicio = criarLista();

    struct elemento aluno;

    do {
        printf("\n============MENU============\n");
        printf("1. Inserir no Início\n");
        printf("2. Inserir no Final\n");
        printf("3. Inserir Ordenadamente\n");
        printf("4. Remover Matrícula\n");
        printf("5. Remover Início\n");
        printf("6. Tamanho da Lista\n");
        printf("7. Lista Vazia\n");
        printf("8. Lista Cheia\n");
        printf("9. Consulta pela Matrícula\n");
        printf("10. Consulta pela Posição\n");
        printf("11. Imprime Lista\n");
        printf("0. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n=====INSERIR NO INÍCIO=====\n");

            printf("Digite a matricula: ");
            scanf("%d", &aluno.matricula);

            printf("Digite o nome: ");
            scanf("%s", aluno.nome); 

            printf("Digite a nota 1: ");
            scanf("%f", &aluno.nota1);

            printf("Digite a nota 2: ");
            scanf("%f", &aluno.nota2);

            printf("Digite a nota 3: ");
            scanf("%f", &aluno.nota3);

            if(insereInicio(inicio, aluno)) {
                printf("Inserido com sucesso na Lista!\n");
            } else {
                printf("Lista não foi criada!\n");
            }
            break;

        case 2:
            printf("\n=====INSERIR NO FINAL=====\n");

            printf("Digite a matricula: ");
            scanf("%d", &aluno.matricula);

            printf("Digite o nome: ");
            scanf("%s", aluno.nome); 

            printf("Digite a nota 1: ");
            scanf("%f", &aluno.nota1);

            printf("Digite a nota 2: ");
            scanf("%f", &aluno.nota2);

            printf("Digite a nota 3: ");
            scanf("%f", &aluno.nota3);

            if(insereFinal(inicio, aluno)) {
                printf("Inserido com sucesso na Lista!\n");
            } else {
                printf("Lista não foi criada!\n");
            }
            break;

        case 3:
            printf("\n=====INSERIR ORDENADAMENTE=====\n"); 

            printf("Digite a matricula: ");
            scanf("%d", &aluno.matricula);

            printf("Digite o nome: ");
            scanf("%s", aluno.nome); 

            printf("Digite a nota 1: ");
            scanf("%f", &aluno.nota1);

            printf("Digite a nota 2: ");
            scanf("%f", &aluno.nota2);

            printf("Digite a nota 3: ");
            scanf("%f", &aluno.nota3);

            if(insereOrdenado(inicio, aluno)) {
                printf("Inserido com sucesso na Lista!\n");
            } else {
                printf("Lista não foi criada!\n");
            }
            break;

        case 4:
            printf("\n====REMOVER PELA MATRÍCULA====\n");

            printf("Digite a matrícula: ");
            scanf("%d", &matricula);

            if(removeMatricula(inicio, matricula)) {
                printf("Matrícula removida com sucesso!\n");
            } else {
                printf("Elemento não encontrado na Lista!\n");
            }
            break;

        case 5:
            printf("\n====REMOVER O INÍCIO====\n");

            if(removeInicio(inicio)) {
                printf("Início removido com sucesso!\n");
            } else {
                printf("Erro ao remover o início da lista\n");
            }
            break;

        case 6:
            printf("\n========TAMANHO========\n");
            printf("Tamanho da Lista: %d\n", tamanhoLista(inicio));
            break;

        case 7:
            if(listaVazia(inicio)) {
                printf("A lista está vazia.\n");
            } else {
                printf("A lista não está vazia\n");
            }
            break;

        case 8:
            if(listaCheia(inicio)) {
                printf("A lista está cheia.\n");
            } else {
                printf("A lista não está cheia\n");
            }
            break; 

        case 9:
            printf("\n=====CONSULTA PELA MATRÍCULA=====\n");

            printf("Digite a matrícula: ");
            scanf("%d", &matricula);

            if(consultaMatricula(inicio, matricula, &aluno)) {
                printf("\nAluno Encontrado:\n");
                printf("Matrícula: %d\n", aluno.matricula);
                printf("Nome: %s \n", aluno.nome);
                printf("Nota 1: %.2f\n", aluno.nota1);
                printf("Nota 2: %.2f\n", aluno.nota2);
                printf("Nota 3: %.2f\n", aluno.nota3);
            } else {
                printf("Elemento não encontrado na Lista!\n");
            }
            break;

        case 10:
            printf("\n=====CONSULTA PELA POSIÇÃO=====\n");

            printf("Digite a posição: ");
            scanf("%d", &posicao);

            if(consultaPosicao(inicio, posicao, &aluno)) {
                printf("\nAluno na Posição %d:\n", posicao);
                printf("Nome: %s | Matricula: %d\n", aluno.nome, aluno.matricula);
                printf("Nota 1: %.2f\n", aluno.nota1);
                printf("Nota 2: %.2f\n", aluno.nota2); 
                printf("Nota 3: %.2f\n", aluno.nota3); 
            } else {
                printf("Posição inválida ou elemento não encontrado na Lista!\n");
            }
            break; 

        case 11:
            printf("\n======IMPRESSÃO DAS LISTAS======\n");
            imprimeLista(inicio);
            break;

        case 0:
            printf("Você saiu!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    } while (opcao != 0);

    apagaLista(inicio);

    return 0;
}
