#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Mostra o array após a iteração
        std::cout << "Array after iteration " << i + 1 << ": ";
        for (const int& value : arr) {
            std::cout << value << " kWh ";
        }
        std::cout << "\n";

        // Se não houve trocas nesta iteração, o array está ordenado
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> energyReadings = {230, 180, 150, 300, 210};

    std::cout << "Original Energy Readings: ";
    for (const int& value : energyReadings) {
        std::cout << value << " kWh ";
    }
    std::cout << "\n\n";

    bubbleSort(energyReadings);

    std::cout << "\nSorted Energy Readings: ";
    for (const int& value : energyReadings) {
        std::cout << value << " kWh ";
    }
    std::cout << "\n";

    return 0;
}
