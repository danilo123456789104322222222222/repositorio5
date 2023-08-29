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

        std::cout << "Iteration " << i << ": ";
        for (const std::string& code : arr) {
            std::cout << code << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::string> productCodes = {
        "P123", "P354", "P011", "P789", "P234"
    };

    std::cout << "Original Codes: ";
    for (const std::string& code : productCodes) {
        std::cout << code << " ";
    }
    std::cout << "\n\n";

    insertionSort(productCodes);

    std::cout << "\nSorted Codes: ";
    for (const std::string& code : productCodes) {
        std::cout << code << " ";
    }
    std::cout << "\n";

    return 0;
}
