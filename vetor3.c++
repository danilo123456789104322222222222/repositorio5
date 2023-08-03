#include <iostream>

int main() {
    const int tamanhovetor = 10;
    int vetor[tamanhovetor];

    std::cout << "Digite " << tamanhovetor << " valores inteiros:" << std::endl;

    // Preenchendo o vetor com valores digitados pelo usuário
    for (int i = 0; i < tamanhovetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    // Calculando a soma dos elementos do vetor
    int soma = 0;
    for (int i = 0; i < tamanhovetor; i++) {
        soma += vetor[i];
    }

    // Exibindo a soma dos elementos do vetor
    std::cout << "A soma dos elementos do vetor é: " << soma << std::endl;

    return 0;
}
