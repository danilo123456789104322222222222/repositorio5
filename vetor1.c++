#include <iostream>

int main() {
    const int tamanhovetor = 5;
    int vetor[tamanhovetor];

    std::cout << "Digite " << tamanhovetor << " valores inteiros:" << std::endl;

    // Preenchendo o vetor com valores digitados pelo usuário
    for (int i = 0; i < tamanhovetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    // Exibindo os elementos do vetor na tela
    std::cout << "Elementos do vetor: ";
    for (int i = 0; i < tamanhovetor; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

