#include <iostream>

int main() {
    // Variável para armazenar a idade
    int idade;

    // Solicitar ao usuário que digite a idade
    std::cout << "Digite a sua idade: ";
    std::cin >> idade;

    // Verificar se a idade é maior ou igual a 18 anos
    if (idade >= 18) {
        std::cout << "Maior de idade" << std::endl;
    } else {
        std::cout << "Menor de idade" << std::endl;
    }

    return 0;
}
