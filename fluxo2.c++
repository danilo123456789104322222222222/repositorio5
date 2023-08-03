#include <iostream>
#include <vector>
using namespace std;

struct Cliente {
    string nome;
    int idade;
    string endereco;
};

vector<Cliente> clientes; // Vetor para armazenar os clientes adicionados

void adicionarCliente() {
    Cliente novoCliente;
    cout << "Digite o nome do cliente: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoCliente.nome);

    cout << "Digite a idade do cliente: ";
    cin >> novoCliente.idade;

    cout << "Digite o endereco do cliente: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoCliente.endereco);

    clientes.push_back(novoCliente);
    cout << "Cliente adicionado com sucesso!" << endl;
}

void removerCliente() {
    int id;
    cout << "Digite o ID do cliente que deseja remover: ";
    cin >> id;

    if (id >= 0 && id < clientes.size()) {
        clientes.erase(clientes.begin() + id);
        cout << "Cliente removido com sucesso!" << endl;
    } else {
        cout << "Cliente nao encontrado!" << endl;
    }
}

void consultarCliente() {
    int id;
    cout << "Digite o ID do cliente que deseja consultar: ";
    cin >> id;

    if (id >= 0 && id < clientes.size()) {
        cout << "Nome: " << clientes[id].nome << endl;
        cout << "Idade: " << clientes[id].idade << endl;
        cout << "Endereco: " << clientes[id].endereco << endl;
    } else {
        cout << "Cliente nao encontrado!" << endl;
    }
}

int main() {
    int opcao;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Adicionar Cliente" << endl;
        cout << "2. Remover Cliente" << endl;
        cout << "3. Consultar Cliente" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                removerCliente();
                break;
            case 3:
                consultarCliente();
                break;
            case 4:
                cout << "Saindo..." << endl;
                return 0;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }

    return 0;
}

