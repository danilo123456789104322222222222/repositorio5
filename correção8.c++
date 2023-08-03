#include <iostream>
using namespace std;

int main() {
   int num = 5;
   int factorial = 1;
   int i = 0;
   do {
        i++;
        factorial *= i;
   } while (i < num);

   cout << "O fatorial de " << num << " é " << factorial << endl;

   return 0;
}
