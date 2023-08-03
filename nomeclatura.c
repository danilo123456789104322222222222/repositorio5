#include <stdio.h> // erro: biblioteca stdio.h não colocada 

int main() {
   int num;
   printf("Digite um numero:");
   scanf("%d", &num);
   for (int i = 1; i <= num; i++) {
      printf("%d\n", i);
   }
   return 0; // erro: ao inves de estar return estava escrito retorn 
}   