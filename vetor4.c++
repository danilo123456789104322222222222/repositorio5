#include <iostream>

int main() {
    const int tamanhoVetor = 8;
    int vetor[tamanhoVetor];

    std::cout << "Digite " << tamanhoVetor << " valores inteiros:" << std::endl;

    // Preenchendo o vetor com valores digitados pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    // Exibindo apenas os elementos pares do vetor
    std::cout << "Elementos pares do vetor: ";
    for (int i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] % 2 == 0) {
            std::cout << vetor[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
