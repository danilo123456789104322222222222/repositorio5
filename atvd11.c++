#include <iostream>
#include <vector>
#include <string>

// Estrutura para representar leituras de temperatura
struct TemperatureReading {
    double temperature;
    std::string unit;

    TemperatureReading(double temp, const std::string& unit) : temperature(temp), unit(unit) {}
};

void bubbleSort(std::vector<TemperatureReading>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].temperature > arr[j + 1].temperature) {
                std::swap(arr[j], arr[j + 1]);
            }
        }

        // Mostra o array após a iteração
        std::cout << "Array after iteration " << i + 1 << ": ";
        for (const TemperatureReading& reading : arr) {
            std::cout << reading.temperature << reading.unit << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<TemperatureReading> temperatureReadings = {
        {125, "°C"},
        {110, "°C"},
        {135, "°C"},
        {120, "°C"},
        {130, "°C"}
    };

    std::cout << "Original Temperature Readings: ";
    for (const TemperatureReading& reading : temperatureReadings) {
        std::cout << reading.temperature << reading.unit << " ";
    }
    std::cout << "\n\n";

    bubbleSort(temperatureReadings);

    std::cout << "\nSorted Temperature Readings: ";
    for (const TemperatureReading& reading : temperatureReadings) {
        std::cout << reading.temperature << reading.unit << " ";
    }
    std::cout << "\n";

    return 0;
}
