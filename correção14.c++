#include <iostream>
using namespace std;

int main() {
    string text;
    cout << "Digite um texto: ";
    getline(cin, text);

    if (text != "")
        cout << "O texto não está vazio." << endl;
    else
        cout << "O texto está vazio." << endl;

    return 0;
}
