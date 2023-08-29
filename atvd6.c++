#include <iostream>

struct TemperatureReading {
    float temperature;
    TemperatureReading* next;

    TemperatureReading(float temp) : temperature(temp), next(nullptr) {}
};

void insertionSortLinkedList(TemperatureReading*& head) {
    if (!head || !head->next) {
        return;  // Lista vazia ou com apenas um elemento, não há necessidade de ordenar
    }

    TemperatureReading* sorted = nullptr;
    TemperatureReading* current = head;

    while (current != nullptr) {
        TemperatureReading* next = current->next;

        if (sorted == nullptr || sorted->temperature >= current->temperature) {
            current->next = sorted;
            sorted = current;
        } else {
            TemperatureReading* temp = sorted;
            while (temp->next != nullptr && temp->next->temperature < current->temperature) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;

        // Mostra a lista após cada inserção
        TemperatureReading* temp = sorted;
        std::cout << "List after insertion: ";
        while (temp != nullptr) {
            std::cout << temp->temperature << "°C ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    head = sorted;
}

int main() {
    TemperatureReading* readings = new TemperatureReading(28.5);
    readings->next = new TemperatureReading(23.8);
    readings->next->next = new TemperatureReading(32.1);
    readings->next->next->next = new TemperatureReading(26.7);
    readings->next->next->next->next = new TemperatureReading(29.3);

    std::cout << "Original List: ";
    TemperatureReading* temp = readings;
    while (temp != nullptr) {
        std::cout << temp->temperature << "°C ";
        temp = temp->next;
    }
    std::cout << "\n\n";

    insertionSortLinkedList(readings);

    std::cout << "\nSorted List: ";
    temp = readings;
    while (temp != nullptr) {
        std::cout << temp->temperature << "°C ";
        temp = temp->next;
    }
    std::cout << "\n";

    // Libera a memória alocada
    while (readings != nullptr) {
        TemperatureReading* temp = readings;
        readings = readings->next;
        delete temp;
    }

    return 0;
}
