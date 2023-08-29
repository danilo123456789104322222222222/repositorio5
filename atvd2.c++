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
    std::vector<int> vehicleSpeeds = {65, 80, 45, 55, 70, 50};
    
    std::cout << "Original Speeds: ";
    for (int speed : vehicleSpeeds) {
        std::cout << speed << " ";
    }
    std::cout << "\n";

    bubbleSort(vehicleSpeeds);

    std::cout << "Sorted Speeds: ";
    for (int speed : vehicleSpeeds) {
        std::cout << speed << " ";
    }
    std::cout << "\n";

    return 0;
}
