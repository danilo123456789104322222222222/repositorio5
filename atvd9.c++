#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<double>> Matrix;

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (const double& value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void modifiedSelectionSort(Matrix& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            int minIndex = j;

            for (int k = j + 1; k < cols; ++k) {
                if (mat[i][k] < mat[i][minIndex]) {
                    minIndex = k;
                }
            }

            std::swap(mat[i][j], mat[i][minIndex]);
        }

        // Mostra a matriz após cada iteração
        std::cout << "Matrix after iteration " << i + 1 << ":\n";
        printMatrix(mat);
        std::cout << "\n";
    }
}

int main() {
    Matrix defectRates = {
        {0.02, 0.08, 0.04},
        {0.05, 0.12, 0.09},
        {0.03, 0.06, 0.07}
    };

    std::cout << "Original Defect Rates:\n";
    printMatrix(defectRates);
    std::cout << "\n";

    modifiedSelectionSort(defectRates);

    std::cout << "\nSorted Defect Rates:\n";
    printMatrix(defectRates);
    std::cout << "\n";

    return 0;
}
