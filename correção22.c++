#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int num = 0;
    for (int i = 0; i < 5; i++) {
        arr[i] = num;
        num += 2; // Incrementa 2 para obter o próximo número par
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
