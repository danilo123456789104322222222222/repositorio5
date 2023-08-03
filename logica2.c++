#include <iostream>

int main() {
    int n; // mudar o nome do (var)
    std::cout << "Digite um número: ";
    std::cin >> n;
    int square = n * n; // colocar essa (var) perto da outra (var) para não se confundir 
    std::cout << "O quadrado do número é: " << square << std::endl;
    return 0;
}
