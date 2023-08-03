#include <iostream>
#include <cstdlib> // Biblioteca para gerar números aleatórios
#include <ctime>   // Biblioteca para usar o tempo como semente

int main() {
    const int tamanhoVetor = 4;
    int vetor[tamanhoVetor];

    // Usando o tempo atual como semente para gerar números aleatórios
    std::srand(static_cast<unsigned>(std::time(0)));

    // Preenchendo o vetor com valores aleatórios entre 1 e 10
    for (int i = 0; i < tamanhoVetor; i++) {
        vetor[i] = std::rand() % 10 + 1;
    }

    // Exibindo o vetor com valores aleatórios (apenas para fins de depuração)
    std::cout << "Vetor com valores aleatórios: ";
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    // Pedindo ao usuário para adivinhar um número do vetor
    int palpite;
    std::cout << "Tente adivinhar um dos números do vetor (entre 1 e 10): ";
    std::cin >> palpite;

    // Verificando se o palpite do usuário está correto
    bool correto = false;
    for (int i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] == palpite) {
            correto = true;
            break;
        }
    }

    // Exibindo o resultado do palpite do usuário
    if (correto) {
        std::cout << "Parabéns! Você acertou o palpite!" << std::endl;
    } else {
        std::cout << "Que pena! O palpite está incorreto. Tente novamente!" << std::endl;
    }

    return 0;
}
