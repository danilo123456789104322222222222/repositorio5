#include <iostream>
#include <cmath> // Incluímos a biblioteca cmath para usar a função sqrt()
using namespace std;

int main() {
    int num;
    cout << "Digite um número: ";
    cin >> num;

    bool is_prime = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            is_prime = false;
            break;
        }
    }

    if (num <= 1)
        is_prime = false;

    if (is_prime)
        cout << num << " é um número primo." << endl;
    else
        cout << num << " não é um número primo." << endl;

    return 0;
}
