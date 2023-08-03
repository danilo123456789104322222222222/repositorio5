#include <iostream>

// Bloco 1
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

// Bloco 2
int main() {
    int num1 = 5;
    int num2 = 3;

    int resultado_soma = soma(num1, num2);
    int resultado_subtracao = subtracao(num1, num2);
    int resultado_multiplicacao = multiplicacao(num1, num2);

    std::cout << "Soma: " << resultado_soma << std::endl;
    std::cout << "Subtração: " << resultado_subtracao << std::endl;
    std::cout << "Multiplicação: " << resultado_multiplicacao << std::endl;

    return 0;
}

