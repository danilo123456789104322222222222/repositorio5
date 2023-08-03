#include <iostream>
#include <cctype> // Incluímos a biblioteca cctype para usar a função tolower()
using namespace std;

int main() {
    char letter;
    cout << "Digite uma letra: ";
    cin >> letter;

    // Convertendo a letra para minúscula
    letter = tolower(letter);

    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        cout << "A letra é uma vogal." << endl;
    else
        cout << "A letra é uma consoante." << endl;

    return 0;
}
