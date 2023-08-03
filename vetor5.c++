#include <iostream>

int main() {
    const int tamanhoVetor = 7;
    float vetor[tamanhoVetor];

    std::cout << "Digite " << tamanhoVetor << " números reais:" << std::endl;

    // Preenchendo o vetor com valores digitados pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite o elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    // Inicializando as variáveis para armazenar o maior e o menor valor
    float maior = vetor[0];
    float menor = vetor[0];

    // Procurando o maior e o menor valor no vetor
    for (int i = 1; i < tamanhoVetor; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    // Exibindo o maior e o menor valor presente no vetor
    std::cout << "Maior valor: " << maior << std::endl;
    std::cout << "Menor valor: " << menor << std::endl;

    return 0;
}

