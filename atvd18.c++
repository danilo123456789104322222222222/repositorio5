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
        for (const std::string& date : arr) {
            std::cout << date << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::string> expirationDates = {
        "2023-06-15", "2023-08-25", "2023-07-10", "2023-09-30", "2023-08-05"
    };

    std::cout << "Datas de vencimento originais: ";
    for (const std::string& date : expirationDates) {
        std::cout << date << " ";
    }
    std::cout << "\n\n";

    selectionSort(expirationDates);

    std::cout << "\nDatas de vencimento ordenadas: ";
    for (const std::string& date : expirationDates) {
        std::cout << date << " ";
    }
    std::cout << "\n";

    return 0;
}
