#include <iostream>

int main() {
    // Variáveis para armazenar os números digitados pelo usuário
    int numero1, numero2;

    // Solicitar ao usuário que digite o primeiro número
    std::cout << "Digite o primeiro numero: ";
    std::cin >> numero1;

    // Solicitar ao usuário que digite o segundo número
    std::cout << "Digite o segundo numero: ";
    std::cin >> numero2;

    // Calcular a soma dos números
    int soma = numero1 + numero2;

    // Exibir o resultado da soma
    std::cout << "A soma dos numeros e: " << soma << std::endl;

    return 0;
}
