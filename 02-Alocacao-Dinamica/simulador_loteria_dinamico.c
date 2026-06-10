#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int *p, aleatorio[6], palpite[6], comp = 0;

    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        aleatorio[i] = (rand() % 60) + 1;
    }

    printf("Digite 6 palpites da loteria (1 - 60): \n");
    for (int i = 0; i < 6; i++) {
        printf("Palpite %d:\n", i + 1);
        scanf("%d", &palpite[i]);        
    }    

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(aleatorio[i] == palpite[j]) {
                comp++;
                break;
            }
        }
    }

    if(p == NULL) {
        printf("ERRO: Overflow!\n");
        return 1;
    }

    p = calloc(comp, sizeof(int));

    int k = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(aleatorio[i] == palpite[j]) {
                p[k] = palpite[j];
                k++;
                break;
            }
        }
    }

    printf("\nNÚMEROS SORTEADOS\n");
    for(int i = 0; i < 6; i++) {
        printf("%d\n", aleatorio[i]);
    }

    printf("\n\nSEUS NÚMEROS CORRETOS (Acertos: %d):\n", comp);
    if (comp > 0) {
        for(int i = 0; i < comp; i++) {
            printf("%d ", p[i]);
        }
    } else {
        printf("Nenhum acerto.");
    }

    printf("\n");

    if (p != NULL) {
        free(p);
    }

    return 0;
}
