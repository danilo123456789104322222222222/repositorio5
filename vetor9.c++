#include <iostream>

int main() {
    const int tamanhoVetor = 5;
    int vetor1[tamanhoVetor];
    int vetor2[tamanhoVetor];
    int vetorResultado[tamanhoVetor];

    std::cout << "Digite " << tamanhoVetor << " valores inteiros para o vetor 1:" << std::endl;

    // Preenchendo o vetor1 com valores digitados pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor1[i];
    }

    std::cout << "Digite " << tamanhoVetor << " valores inteiros para o vetor 2:" << std::endl;

    // Preenchendo o vetor2 com valores digitados pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor2[i];
    }

    // Realizando a soma dos elementos dos vetores e armazenando no vetorResultado
    for (int i = 0; i < tamanhoVetor; i++) {
        vetorResultado[i] = vetor1[i] + vetor2[i];
    }

    // Exibindo o conteúdo do vetorResultado
    std::cout << "Vetor Resultado: ";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << vetorResultado[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
