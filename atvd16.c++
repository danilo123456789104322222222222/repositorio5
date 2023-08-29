#include <iostream>
#include <vector>

void insertionSort(std::vector<double>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main() {
    std::vector<double> pollutantMeasurements = {2.5, 1.8, 3.0, 2.2, 2.8};

    std::cout << "Original Pollutant Measurements: ";
    for (double measurement : pollutantMeasurements) {
        std::cout << measurement << " ppm ";
    }
    std::cout << "\n\n";

    insertionSort(pollutantMeasurements);

    std::cout << "Sorted Pollutant Measurements: ";
    for (double measurement : pollutantMeasurements) {
        std::cout << measurement << " ppm ";
    }
    std::cout << "\n";

    return 0;
}
