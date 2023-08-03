#include <iostream> // erro #include escrito da forma errada

int main() { // erro: faltou ()
   int num;
   std::cout << "Digite um número: "; // erro: faltava std::
   std::cin >> num;
   if (num % 2 == 0)
        std::cout << num << " é um número par." << std::endl;
   else
        std::cout << num << " é um número ímpar." << std::endl;
   return 0;
}

