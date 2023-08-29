#include <iostream>
#include <vector>
#include <string>

void selectionSort(std::vector<std::string>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);

        // Mostra o array após a seleção
        std::cout << "Após a seleção " << i + 1 << ": ";
        for (const std::string& id : arr) {
            std::cout << id << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::string> machineIDs = {
        "M567", "M123", "M789", "M234", "M011"
    };

    std::cout << "IDs originais das máquinas: ";
    for (const std::string& id : machineIDs) {
        std::cout << id << " ";
    }
    std::cout << "\n\n";

    selectionSort(machineIDs);

    std::cout << "\nIDs das máquinas ordenados: ";
    for (const std::string& id : machineIDs) {
        std::cout << id << " ";
    }
    std::cout << "\n";

    return 0;
}
