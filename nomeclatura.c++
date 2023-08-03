#include <iostream> // erro #include escrito da forma errada, faltando a # e sem espaçamento do iostream

int main() {
   int i, n;
   int soma = 0;
   std::cout << "Digite um numero: "; // erro: falta do std::
   std::cin >> n; // erro: falta do std::
   for(i = 0; i <= n; i++)
   {
        soma += i;
   }
  std::cout << "A soma dos numeros de 0 a " << n << " eh " << soma << std::endl; // erro: falta do std::  falta do std:: entre o endl
   return 0; // erro: return escrito da forma errada
}