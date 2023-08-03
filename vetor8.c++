#include <iostream>

int main() {
    const int tamanhoVetor = 10;
    int vetor[tamanhoVetor];

    std::cout << "Digite " << tamanhoVetor << " valores inteiros:" << std::endl;

    // Preenchendo o vetor com valores digitados pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    // Calculando a soma dos elementos do vetor
    int soma = 0;
    for (int i = 0; i < tamanhoVetor; i++) {
        soma += vetor[i];
    }

    // Calculando a média dos valores presentes no vetor
    float media = static_cast<float>(soma) / tamanhoVetor;

    // Exibindo a média dos valores presentes no vetor
    std::cout << "A média dos valores presentes no vetor é: " << media << std::endl;

    return 0;
}
