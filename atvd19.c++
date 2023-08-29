#include <iostream>
#include <vector>
#include <algorithm>

// Definindo um tipo para representar os tempos de ciclo
typedef double Time;

// Função para imprimir a matriz
void printMatrix(const std::vector<std::vector<Time>>& matrix) {
    for (const auto& row : matrix) {
        for (Time value : row) {
            std::cout << value << " s\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Função para realizar o Selection Sort em uma matriz
void selectionSortMatrix(std::vector<std::vector<Time>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            int minIndex = j;

            for (int k = j + 1; k < cols; ++k) {
                if (matrix[i][k] < matrix[i][minIndex]) {
                    minIndex = k;
                }
            }

            std::swap(matrix[i][j], matrix[i][minIndex]);
        }

        // Mostra a matriz após a seleção
        std::cout << "Após a selecao na etapa " << i + 1 << ":\n";
        printMatrix(matrix);

        std::cout << "Explicação:\n";
        std::cout << "A ordenação dos tempos de ciclo é crucial para o funcionamento coordenado da linha de produção:\n";
        std::cout << "- Sincronização de Processos: Garante que as etapas da linha de produção estejam sincronizadas.\n";
        std::cout << "- Otimização da Produção: Permite executar etapas com tempos menores primeiro, otimizando o fluxo.\n";
        std::cout << "- Minimização de Atrasos: Reduz a possibilidade de atrasos entre as diferentes etapas.\n";
        std::cout << "- Produção Consistente: Evita variações significativas nos tempos de ciclo entre as etapas.\n";
        std::cout << "- Manutenção de Qualidade: Contribui para a produção de produtos de melhor qualidade.\n";
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<Time>> cycleTimes = {
        {10.2, 8.5, 12.1},
        {15.6, 9.8, 11.4},
        {7.2, 14.3, 13.0}
    };

    std::cout << "Matriz de tempos de ciclo original:\n";
    printMatrix(cycleTimes);

    selectionSortMatrix(cycleTimes);

    std::cout << "\nMatriz de tempos de ciclo ordenada:\n";
    printMatrix(cycleTimes);

    return 0;
}
