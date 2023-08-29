#include <iostream>
#include <vector>
#include <string>

void optimizedBubbleSort(std::vector<std::string>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Se nenhum swap ocorreu nesta iteração, o array está ordenado
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<std::string> arrivalDates = {
        "2023-09-10", "2023-08-15", "2023-08-25", "2023-09-30", "2023-08-05"
    };

    std::cout << "Original Arrival Dates:\n";
    for (const std::string& date : arrivalDates) {
        std::cout << date << "\n";
    }
    std::cout << "\n";

    optimizedBubbleSort(arrivalDates);

    std::cout << "Sorted Arrival Dates:\n";
    for (const std::string& date : arrivalDates) {
        std::cout << date << "\n";
    }
    std::cout << "\n";

    return 0;
}

