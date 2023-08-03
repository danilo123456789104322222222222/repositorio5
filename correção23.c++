#include <iostream>
using namespace std;

int main() {
    int arr[5] = {3, 1, 5, 2, 4};
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; // Corrigimos para usar 'temp' aqui
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
