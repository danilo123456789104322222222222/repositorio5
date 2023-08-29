#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);

        // Mostra o array após cada iteração de seleção
        std::cout << "Array after iteration " << i + 1 << ": ";
        for (const int& time : arr) {
            std::cout << time << "h ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> operationTimes = {120, 90, 150, 80, 110};

    std::cout << "Original Operation Times: ";
    for (const int& time : operationTimes) {
        std::cout << time << "h ";
    }
    std::cout << "\n\n";

    selectionSort(operationTimes);

    std::cout << "\nSorted Operation Times: ";
    for (const int& time : operationTimes) {
        std::cout << time << "h ";
    }
    std::cout << "\n";

    return 0;
}
