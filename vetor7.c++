#include <iostream>

int main() {
    const int tamanhoVetor = 5;
    char vetor[tamanhoVetor];

    std::cout << "Digite " << tamanhoVetor << " letras do alfabeto:" << std::endl;

    // Preenchendo o vetor com letras do alfabeto digitadas pelo usuário
    for (int i = 0; i < tamanhoVetor; i++) {
        std::cout << "Digite a letra " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    // Pedindo ao usuário a letra que deseja verificar
    char letra;
    std::cout << "Digite a letra que deseja verificar: ";
    std::cin >> letra;

    // Verificando se a letra está presente no vetor
    bool presente = false;
    for (int i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] == letra) {
            presente = true;
            break;
        }
    }

    // Exibindo o resultado da verificação
    if (presente) {
        std::cout << "A letra " << letra << " está presente no vetor." << std::endl;
    } else {
        std::cout << "A letra " << letra << " não está presente no vetor." << std::endl;
    }

    return 0;
}
