#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int num = 1;
    for (int i = 0; i < 5; i++) {
        if (num % 2 != 0) {
            arr[i] = num;
        }
        num++;
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}