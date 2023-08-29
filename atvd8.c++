#include <iostream>
#include <vector>
#include <string>

void modifiedSelectionSort(std::vector<std::string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i) {
        int minIndex = i;
        int maxIndex = i;

        for (int j = i + 1; j < n - i; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        std::swap(arr[n - i - 1], arr[maxIndex]);

        // Mostra o array após cada troca
        std::cout << "Array after iteration " << i + 1 << ": ";
        for (const std::string& result : arr) {
            std::cout << result << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::string> testResults = {"Pass", "Fail", "Pass", "Pass", "Fail"};

    std::cout << "Original Test Results: ";
    for (const std::string& result : testResults) {
        std::cout << result << " ";
    }
    std::cout << "\n\n";

    modifiedSelectionSort(testResults);

    std::cout << "\nSorted Test Results: ";
    for (const std::string& result : testResults) {
        std::cout << result << " ";
    }
    std::cout << "\n";

    return 0;
}
