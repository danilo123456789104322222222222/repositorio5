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
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main() {
    std::vector<std::string> serialNumbers = {
        "SN456", "SN123", "SN789", "SN234", "SN567"
    };

    std::cout << "Original Serial Numbers: ";
    for (const std::string& serial : serialNumbers) {
        std::cout << serial << " ";
    }
    std::cout << "\n\n";

    insertionSort(serialNumbers);

    std::cout << "\nSorted Serial Numbers: ";
    for (const std::string& serial : serialNumbers) {
        std::cout << serial << " ";
    }
    std::cout << "\n";

    return 0;
}
