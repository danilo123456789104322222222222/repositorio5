#include <iostream>
#include <vector>
#include <string>

struct ProductSample {
    int weight;
    std::string unit;

    ProductSample(int w, const std::string& u) : weight(w), unit(u) {}
};

void insertionSort(std::vector<ProductSample>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        ProductSample key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].weight > key.weight) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;

        // Mostra o array após a inserção
        std::cout << "Array after insertion " << i << ": ";
        for (const ProductSample& sample : arr) {
            std::cout << sample.weight << sample.unit << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<ProductSample> productSamples = {
        {150, "g"}, {125, "g"}, {175, "g"}, {130, "g"}, {160, "g"}
    };

    std::cout << "Original Product Weights: ";
    for (const ProductSample& sample : productSamples) {
        std::cout << sample.weight << sample.unit << " ";
    }
    std::cout << "\n\n";

    insertionSort(productSamples);

    std::cout << "\nSorted Product Weights: ";
    for (const ProductSample& sample : productSamples) {
        std::cout << sample.weight << sample.unit << " ";
    }
    std::cout << "\n";

    return 0;
}
