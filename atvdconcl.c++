#include <iostream>

int main() {
    int estoqueInicial;
    int estoqueMinimo;
    int estoqueMaximo;
    int quantidadeVendida;
    int quantidadeRecebida;
    int estoqueAtual;
    // Passo 1: Obter os valores iniciais do estoque
    std::cout << "Informe o estoque inicial: ";
    std::cin >> estoqueInicial;

    std::cout << "Informe o estoque mínimo: ";
    std::cin >> estoqueMinimo;

    std::cout << "Informe o estoque máximo: ";
    std::cin >> estoqueMaximo;

    std::cout << "Informe a quantidade vendida: ";
    std::cin >> quantidadeVendida;

    std::cout << "Informe a quantidade recebida: ";
    std::cin >> quantidadeRecebida;

    // Passo 2: Calcular o estoque atual
    estoqueAtual = estoqueInicial + quantidadeRecebida - quantidadeVendida;

    // Passo 3: Verificar se o estoque está abaixo do mínimo
    if (estoqueAtual < estoqueMinimo) {
        std::cout << "Estoque abaixo do mínimo. Faça um pedido de compra!" << std::endl;
    }

    // Passo 4: Verificar se o estoque está acima do máximo
    if (estoqueAtual > estoqueMaximo) {
        std::cout << "Estoque acima do máximo. Tome medidas para reduzir o estoque!" << std::endl;
    }

    // Passo 5: Atualizar o estoque inicial
    estoqueInicial = estoqueAtual;

    // Exibir o estoque atualizado
    std::cout << "Estoque atual: " << estoqueAtual << std::endl;

    return 0;
}