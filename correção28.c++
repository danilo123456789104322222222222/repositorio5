#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // Verifica se o índice está dentro dos limites do vetor
    if (10 >= 0 && 10 < 5) {
        cout << arr[10] << endl;
    } else {
        cout << "O índice está fora dos limites do vetor." << endl;
    }

    return 0;
}
