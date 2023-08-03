#include <iostream>

int main () {
    int numero1, numero2, numero3;
    int media;

    std::cout << "Digite o primeiro numero inteiro ";
    std::cin >> numero1;

    std::cout << "Digite o segundo numero inteiro ";
    std::cin >> numero2;

    std::cout << "Digite o terceiro numero inteiro ";
    std::cin >> numero3;

    media = (numero1 + numero2 + numero3) / 3.0; 

    std::cout << " a media do numero e: " << media << std::endl;


    return 0;
 
}
