#include <iostream>

int main() {
    int opcao;

    std::cout << "Digite uma opcao (1-4): ";
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            std::cout << "opcao 1 selecionada." << std::endl;
            break;
         case 2:
         std::cout << "opcao 2 selecionada." << std::endl;
         break;
         case 3:
            std::cout << "opcao 3 selecioanada." << std::endl;
            break;
        case 4:
            std::cout << "sou um programador jr." << std::endl;
            break;
            default:
                std::cout << "opcao invalida." << std::endl;

    }

    return 0;

}