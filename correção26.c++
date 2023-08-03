#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int max = arr[0];
    for (int i = 1; i < 5; i++) { // Corrigimos para 'i < 5'
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "O maior elemento do vetor é: " << max << endl;

    return 0;
}
