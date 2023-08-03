#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    if (sizeof(arr) / sizeof(arr[0]) == 0) {
        cout << "O vetor está vazio." << endl;
    } else {
        cout << "O vetor não está vazio." << endl;
    }

    return 0;
}
