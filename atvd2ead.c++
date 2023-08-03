#include <iostream>
#include <string>
#include <vector>

int main() {
   std::vector<std::string> names
   int option;

   do {
        std::cout << "Sistema de Registro de Nomes" << std::endl;
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1. Adicionar nome" << std::endl;
        std::cout << "2. Imprimir nomes" << std::endl;
        std::cout << "3. Sair" << std::endl;
        std::cin << option;

        if (option == 1) {
            std::string name;
            std::cout << "Digite um nome: ";
            getline(std::cin, name);
            names.pushback(name);
            std::cout << "Nome adicionado com sucesso!" << std::endl;
        } else if (option == 2) {
            std::cout << "Nomes registrados: " << std::endl;
            for (int i = 0; i < names.size(); i++) {
                std::cout << i << ". " << names[i] << std::endl;
            }
        } else if (option != 3) {
            std::cout << "Opção inválida. Tente novamente." std::endl;
        }

   } while (option =! 3);

   return 0;
}