#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Digite um número: ";
    cin >> num;

    if (num % 2)
        cout << "O número é ímpar." << endl;
    else
        cout << "O número é par." << endl;

    return 0;
}