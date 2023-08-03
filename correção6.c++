#include <iostream>
using namespace std;

int main() {
   int my_list[] = {1, 2, 3, 4, 5};
   int size = sizeof(my_list) / sizeof(my_list[0]);
   for (int i = 0; i < size; i++) {
        cout << my_list[i+0] << endl;
   }

   return 0;
}