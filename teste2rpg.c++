#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Personagem {
public:
    void adicionar_item(const std::string& item) {
        equipamentos.push_back(item);
        std::cout << item << " foi adicionado à lista de equipamentos." << std::endl;
    }

    void remover_item(const std::string& nome_item) {
        auto it = std::find_if(equipamentos.begin(), equipamentos.end(), [&](const std::string& item) {
            return to_lower_case(item) == to_lower_case(nome_item);
        });

        if (it != equipamentos.end()) {
            equipamentos.erase(it);
            std::cout << *it << " foi removido da lista de equipamentos." << std::endl;
        } else {
            std::cout << nome_item << " não foi encontrado na lista de equipamentos." << std::endl;
        }
    }

    void exibir_equipamentos() {
        if (equipamentos.empty()) {
            std::cout << "A lista de equipamentos está vazia." << std::endl;
        } else {
            std::cout << "Lista de equipamentos:" << std::endl;
            for (const auto& item : equipamentos) {
                std::cout << item << std::endl;
            }
        }
    }

    void buscar_item(const std::string& nome_item) {
        auto it = std::find_if(equipamentos.begin(), equipamentos.end(), [&](const std::string& item) {
            return to_lower_case(item) == to_lower_case(nome_item);
        });

        if (it != equipamentos.end()) {
            std::cout << *it << " está na lista de equipamentos." << std::endl;
        } else {
            std::cout << nome_item << " não foi encontrado na lista de equipamentos." << std::endl;
        }
    }

private:
    std::vector<std::string> equipamentos;

    static std::string to_lower_case(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

int main() {
    std::cout << "Bem-vindo ao RPG do Personagem!" << std::endl;

    Personagem personagem;

    while (true) {
        std::cout << "\nEscolha uma opção:" << std::endl;
        std::cout << "1. Adicionar item" << std::endl;
        std::cout << "2. Remover item" << std::endl;
        std::cout << "3. Exibir equipamentos" << std::endl;
        std::cout << "4. Buscar item" << std::endl;
        std::cout << "5. Sair" << std::endl;

        int opcao;
        std::cin >> opcao;

        if (opcao == 1) {
            std::string item;
            std::cout << "Digite o nome do item que deseja adicionar: ";
            std::cin >> item;
            personagem.adicionar_item(item);
        } else if (opcao == 2) {
            std::string item;
            std::cout << "Digite o nome do item que deseja remover: ";
            std::cin >> item;
            personagem.remover_item(item);
        } else if (opcao == 3) {
            personagem.exibir_equipamentos();
        } else if (opcao == 4) {
            std::string item;
            std::cout << "Digite o nome do item que deseja buscar: ";
            std::cin >> item;
            personagem.buscar_item(item);
        } else if (opcao == 5) {
            std::cout << "Encerrando o programa." << std::endl;
            break;
        } else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}