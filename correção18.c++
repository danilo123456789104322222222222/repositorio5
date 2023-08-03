#include <iostream>
using namespace std;

int main() {
    int idade;
    cout << "Digite sua idade: ";
    cin >> idade;

    if (idade >= 0) {
        if (idade >= 18)
            cout << "Você é maior de idade." << endl;
        else
            cout << "Você é menor de idade." << endl;
    } else {
        cout << "A idade não pode ser um valor negativo." << endl;
    }

    return 0;
}
