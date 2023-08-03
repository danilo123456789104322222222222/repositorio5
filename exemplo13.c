#include <stdio.h>
// bloco 1
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}
//bloco 2 
int main() {
    int num1 = 5;
    int num2 = 3;

    int resultado_soma = soma(num1, num2);
    int resultado_subtracao = subtracao(num1, num2);
    int resultado_multiplicacao = multiplicacao(num1, num2);

    printf("Soma: %d\n", resultado_soma);
    printf("Subtração: %d\n", resultado_subtracao);
    printf("Multiplicação: %d\n", resultado_multiplicacao);

    return 0;
}