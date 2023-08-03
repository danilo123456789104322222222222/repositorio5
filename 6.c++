#include <iostream>

int main() {
    // Variáveis para armazenar as notas
    double nota1, nota2, nota3;

    // Solicitar ao usuário que digite as três notas
    std::cout << "Digite a primeira nota: ";
    std::cin >> nota1;

    std::cout << "Digite a segunda nota: ";
    std::cin >> nota2;

    std::cout << "Digite a terceira nota: ";
    std::cin >> nota3;

    // Calcular a média das três notas
    double media = (nota1 + nota2 + nota3) / 3;

    // Exibir o resultado da média na tela
    std::cout << "A media das tres notas e: " << media << std::endl;

    return 0;
}
