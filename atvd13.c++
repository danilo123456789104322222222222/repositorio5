#include <iostream>
#include <vector>
#include <string>

void insertionSort(std::vector<std::string>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        std::string key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;

        // Mostra o array após a inserção
        std::cout << "Array after insertion " << i << ": ";
        for (const std::string& id : arr) {
            std::cout << id << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::string> componentIDs = {
        "C123", "C789", "C234", "C567", "C011"
    };

    std::cout << "Original Component IDs: ";
    for (const std::string& id : componentIDs) {
        std::cout << id << " ";
    }
    std::cout << "\n\n";

    insertionSort(componentIDs);

    std::cout << "\nSorted Component IDs: ";
    for (const std::string& id : componentIDs) {
        std::cout << id << " ";
    }
    std::cout << "\n";

    return 0;
}
