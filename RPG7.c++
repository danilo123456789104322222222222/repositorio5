#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

// ...

int main() {
    // ...

    // Sistema de equipamento e inventário
    const int TRAVA_OPCAO_EQUIPAMENTO = 5;
    while (true) {
        std::cout << "\n=== Equipamento e Inventário ===" << std::endl;
        std::cout << "1. Exibir arma equipada" << std::endl;
        std::cout << "2. Equipar arma" << std::endl;
        std::cout << "3. Adicionar item ao inventário" << std::endl;
        std::cout << "4. Remover item do inventário" << std::endl;
        std::cout << "5. Exibir todos os itens do inventário" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";

        int opcao;
        std::string input;
        std::getline(std::cin, input);

        // Verificar se o input possui apenas um caractere e é um dígito numérico
        if (input.length() == 1 && std::isdigit(input[0])) {
            opcao = std::stoi(input);
            if (opcao >= 1 && opcao <= TRAVA_OPCAO_EQUIPAMENTO) {
                if (opcao == 1) {
                    // Resto do código para a opção 1...
                } else if (opcao == 2) {
                    // Resto do código para a opção 2...
                } else if (opcao == 3) {
                    // Resto do código para a opção 3...
                } else if (opcao == 4) {
                    // Resto do código para a opção 4...
                } else if (opcao == 5) {
                    // Resto do código para a opção 5...
                } else if (opcao == 0) {
                    break;
                }
            } else {
                std::cout << "Opção inválida. Tente novamente." << std::endl;
            }
        } else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
