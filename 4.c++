#include <iostream>

bool ehPrimo(int numero) {
    if (numero <= 1) {
        return false; // Números menores ou iguais a 1 não são primos
    }

    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false; // Se o número é divisível por algum valor entre 2 e a raiz quadrada dele, não é primo
        }
    }

    return true; // Caso contrário, é primo
}

int main() {
    int numero;

    // Solicitar ao usuário que digite o número inteiro
    std::cout << "Digite um numero inteiro para verificar se eh primo: ";
    std::cin >> numero;

    // Verificar se o número é primo e exibir o resultado
    if (ehPrimo(numero)) {
        std::cout << numero << " e um numero primo." << std::endl;
    } else {
        std::cout << numero << " nao e um numero primo." << std::endl;
    }

    return 0;
}
