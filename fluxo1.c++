#include <iostream>
#include <string>
#include <vector>

struct Cliente {
    std::string nome;
    std::string telefone;
    std::string endereco;
};

void adicionarCliente(std::vector<Cliente>& clientes) {
    Cliente novoCliente;
    std::cout << "Nome: ";
    std::cin.ignore(); // Limpar o buffer do teclado antes de ler a string
    std::getline(std::cin, novoCliente.nome);
    std::cout << "Telefone: ";
    std::getline(std::cin, novoCliente.telefone);
    std::cout << "Endereco: ";
    std::getline(std::cin, novoCliente.endereco);

    clientes.push_back(novoCliente);
    std::cout << "Cliente adicionado com sucesso!\n";
}

void removerCliente(std::vector<Cliente>& clientes) {
    std::string identificador;
    std::cout << "Informe o identificador do cliente a ser removido: ";
    std::getline(std::cin, identificador);

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->nome == identificador || it->telefone == identificador) {
            clientes.erase(it);
            std::cout << "Cliente removido com sucesso!\n";
            return;
        }
    }

    std::cout << "Cliente nao encontrado.\n";
}

void consultarCliente(const std::vector<Cliente>& clientes) {
    std::string identificador;
    std::cout << "Informe o identificador do cliente a ser consultado: ";
    std::getline(std::cin, identificador);

    for (const auto& cliente : clientes) {
        if (cliente.nome == identificador || cliente.telefone == identificador) {
            std::cout << "Informacoes do cliente:\n";
            std::cout << "Nome: " << cliente.nome << "\n";
            std::cout << "Telefone: " << cliente.telefone << "\n";
            std::cout << "Endereco: " << cliente.endereco << "\n";
            return;
        }
    }

    std::cout << "Cliente nao encontrado.\n";
}

int main() {
    std::vector<Cliente> clientes;
    int opcao;

    do {
        std::cout << "Opcoes:\n";
        std::cout << "1: Adicionar Cliente\n";
        std::cout << "2: Remover Cliente\n";
        std::cout << "3: Consultar Cliente\n";
        std::cout << "4: Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarCliente(clientes);
                break;
            case 2:
                removerCliente(clientes);
                break;
            case 3:
                consultarCliente(clientes);
                break;
            case 4:
                std::cout << "O programa sera encerrado.\n";
                break;
            default:
                std::cout << "Opcao invalida, tente novamente.\n";
                break;
        }

    } while (opcao != 4);

    return 0;
}
