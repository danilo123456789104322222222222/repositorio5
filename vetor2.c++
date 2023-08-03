#include <iostream>
#include <string>

int main() {
    const int tamanhovetor = 5;
    std::string frutas[tamanhovetor];

    std::cout << "Digite o nome de " << tamanhovetor << " frutas:" << std::endl;

    // Preenchendo o vetor com os nomes das frutas
    for (int i = 0; i < tamanhovetor; i++) {
        std::cout << "Digite o nome da fruta " << i + 1 << ": ";
        std::cin >> frutas[i];
    }

    // Exibindo os nomes das frutas em linhas separadas
    std::cout << "Nomes das frutas:" << std::endl;
    for (int i = 0; i < tamanhovetor; i++) {
        std::cout << frutas[i] << std::endl;
    }

    return 0;
}