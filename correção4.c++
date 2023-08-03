#include <iostream>
using namespace std;

int main() {
   int sum = 0;
   int num = 1;
   while (num <= 10) {
        sum += num;
        num++; // adivionar uma variavel em cada iteração
   }
   cout << "A soma dos 10 primeiros números é: " << sum << endl;

   return 0;
}