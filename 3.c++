#include <iostream>

// Função para calcular o fatorial de um número 
unsigned long long int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int numero;

    // Solicitar ao usuário que digite o número inteiro
    std::cout << "Digite um numero inteiro para calcular o fatorial: ";
    std::cin >> numero;

    // Verificar se o número é válido (não negativo)
    if (numero < 0) {
        std::cout << "O fatorial de numeros negativos nao e definido." << std::endl;
    } else {
        // Calcular o fatorial e exibir o resultado
        unsigned long long int resultado = fatorial(numero);
        std::cout << "O fatorial de " << numero << " e: " << resultado << std::endl;
    }

    return 0;
}

