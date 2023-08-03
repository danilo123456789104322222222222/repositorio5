#include <stdio.h> // erro: biblioteca #iclude escrito da forma errada

int main(){
   int n1, n2, soma;
   printf("Digite dois numeros: ");
   scanf("%d %d", &n1, &n2);
   soma = n1 + n2;
   printf("A soma dos numeros eh %d\n", soma);
   
   return 0; // erro: return escrito da forma errada 
}