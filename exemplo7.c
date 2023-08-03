#include <stdio.h>

int main() {
    int numeros[5]; // Declaração de um array de 5 elementos

    for (int i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]); // Lê os valores do array

    }

    printf("Elementos do array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]); // Exibe os valores do aray

        }

        return 0;

        }
