#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / 5; // Média como double
    cout << "A média dos elementos do vetor é: " << average << endl;

    return 0;
}
