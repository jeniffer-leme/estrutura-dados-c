#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, num, tam, mult= 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    p = calloc(tam, sizeof(int));

    if(p == NULL) {
        printf("ERRO: Overflow!");
        return 1;
    }

    printf("Digite %d números inteiros: \n", tam);
    for(int i = 0; i < tam; i++) {
        scanf("%d", &p[i]);
    }

    printf("\nDigite um número: ");
    scanf("%d", &num);

    printf("\nMÚLTIPLOS\n");
    for(int i = 0; i < tam; i++) {
        if(p[i] % num == 0) {
            printf("%d ", p[i]);
            mult++;
        } 
    }

    printf("\n\nTOTAL: %d\n", mult);

    free(p);

    return 0;
}
