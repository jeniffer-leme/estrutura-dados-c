#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = malloc(5 * sizeof(int));

    if(p == NULL) {
        printf("Erro! Memória insuficiente.\n");
        return 1;
    }

    printf("Digite 5 números: \n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &p[i]);
    }

    printf("\nNÚMEROS DIGITADOS:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }

    free(p);
  
    return 0;
}  
