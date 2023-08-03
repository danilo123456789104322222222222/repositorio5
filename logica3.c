#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;
    int resultado = 0;

    /* Loop para somar os números de x até y */
    for (int i = x; i <= y; i++) {
        resultado += i;
    }

    printf("A soma dos números de %d até %d é: %d\n", x, y, resultado);

    return 0;
}