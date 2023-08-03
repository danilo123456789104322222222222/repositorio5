#include <iostream>
#include <cmath>

// Função para verificar se um número é divisível por 3
bool ehDivisivelPor3(int num) {
    return num % 3 == 0;
}

// Função para verificar se um número é um quadrado perfeito
bool ehQuadradoPerfeito(int num) {
    int raiz = sqrt(num);
    return raiz * raiz == num;
}

// Função para calcular a soma dos dígitos de um número
int calcularSomaDigitos(int num) {
    int soma = 0;
    while (num != 0) {
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

// Função para encontrar o menor número mágico dentro de um intervalo
int encontrarNumeroMagico(int limiteInferior, int limiteSuperior) {
    for (int num = limiteInferior; num <= limiteSuperior; num++) {
        if (ehDivisivelPor3(num) && ehQuadradoPerfeito(num) && calcularSomaDigitos(num) <= 10) {
            return num;
        }
    }
    return -1; // Caso nenhum número mágico seja encontrado
}

int main() {
    int limiteInferior, limiteSuperior;

    std::cout << "Digite o limite inferior do intervalo: ";
    std::cin >> limiteInferior;

    std::cout << "Digite o limite superior do intervalo: ";
    std::cin >> limiteSuperior;

    int numeroMagico = encontrarNumeroMagico(limiteInferior, limiteSuperior);

    if (numeroMagico != -1) {
        std::cout << "O menor numero magico dentro do intervalo [" << limiteInferior << ", " << limiteSuperior << "] e: " << numeroMagico << std::endl;
    } else {
        std::cout << "Nenhum numero magico encontrado dentro do intervalo [" << limiteInferior << ", " << limiteSuperior << "]" << std::endl;
    }

    return 0;
}