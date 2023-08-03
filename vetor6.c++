#include <iostream>

int main() {
    const int tamanhoVetor = 6;
    int vetorOriginal[tamanhoVetor];
    int vetorInvertido[tamanhoVetor];

    std::cout << "Digite " << tamanhoVetor << " valores inteiros:" << std::endl;

    // Preenchendo o vetorOriginal com valores digitados pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetorOriginal[i];
    }

    // Invertendo a ordem dos elementos e armazenando no vetorInvertido
    for (int i = 0; i < tamanhoVetor; i++) {
        vetorInvertido[i] = vetorOriginal[tamanhoVetor - 1 - i];
    }

    // Exibindo o vetorInvertido
    std::cout << "Vetor invertido: ";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << vetorInvertido[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
