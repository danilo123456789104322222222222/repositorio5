#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::vector<int> productionTimes = {23, 15, 7, 42, 11, 5};
    
    std::cout << "Original Array: ";
    for (int time : productionTimes) {
        std::cout << time << " ";
    }
    std::cout << "\n";

    bubbleSort(productionTimes);

    std::cout << "Sorted Array: ";
    for (int time : productionTimes) {
        std::cout << time << " ";
    }
    std::cout << "\n";

    return 0;
}
