#include <stdio.h>
#include <string.h>

#define NUM 50

typedef struct Pessoa {
    char nome[40];
    float peso;
    float altura;
}pessoa;

void cadastrarPessoa(pessoa p[], int *pos) {

    if(*pos < NUM) {
        printf("\nDigite o seu nome: ");
        fgets(p[*pos].nome, sizeof(p[*pos].nome), stdin);
        p[*pos].nome[strcspn(p[*pos].nome, "\n")] = '\0';

        printf("Digite a sua altura: ");
        scanf("%f", &p[*pos].altura);

        printf("Digite o seu peso: ");
        scanf("%f", &p[*pos].peso);

        (*pos)++;
    } else {
        printf("Limite de pessoas atingido!\n");
    }
}

void calcularPeso(pessoa p[], int pos) {

    printf("\n\n========CÁLCULO IMC========");
    for(int i = 0; i < pos; i++) {
        float imc = p[i].peso / (p[i].altura * p[i].altura);

        printf("\nPessoa n°%d\n", i+1);
        printf("Nome: %s\n", p[i].nome);
        printf("Peso: %.2f\n", p[i].peso);
        printf("Altura: %.2f\n", p[i].altura);
        printf("IMC: %.2f\n", imc);

        if (imc < 18.5) {
            printf("Abaixo do peso!");
        } 
        else if (imc <= 24.9) {
            printf("Peso ideal!");
        } 
        else if (imc <= 29.9) {
            printf("Sobrepeso (Pré-Obesidade)");
        } 
        else if (imc <= 34.9) {
            printf("Obesidade Grau I");
        } 
        else {
            printf("Obesidade Grau III");
        }

        printf("\n");
    }
}

int main() {
    int opcao, pos = 0;
    pessoa p[NUM];

    do {
        printf("\n========MENU========\n");
        printf("1. Cadastrar\n");
        printf("2. Calcular IMC\n");
        printf("0. Sair\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case  1:
            cadastrarPessoa(p, &pos);
            break;

        case 2:
            calcularPeso(p, pos);   
            break;
            
        case 0:
            printf("Você saiu!");
            break;    
        
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            break;
        }

    }while(opcao != 0);

    return 0;
}
