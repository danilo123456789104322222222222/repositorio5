#include <iostream>
using namespace std;

int main() {
   string password;
   do {
        cout << "Digite a senha: ";
        cin >> password;
   } while (password != "12092005"); // tirar a palavra secreto, e adicionar sua propria senha, se estiver errado vai pedir para vc redigitar

   cout << "Senha correta!" << endl;
   return 0;
}
