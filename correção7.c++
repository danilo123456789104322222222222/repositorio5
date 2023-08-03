#include <iostream>
using namespace std;

int main() {
   int num = 7;
   bool is_prime = true;
   int i = 2;
   while (i <= num) {
        if (num % i == 0) {
            is_prime = false;
        }
        i++;
   }
   if (is_prime) {
        cout << num << " é um número primo." << endl;
   } else {
        cout << num << " não é um número primo." << endl;
   }

   return 0;
}