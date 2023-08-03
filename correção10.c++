#include <iostream>
using namespace std;

int main() {
   string word = "level";
   bool is_palindrome = true;
   int i = 0;
   while (i < word.length() / 2) {
        if (word[i] != word[word.length() - i - 1]) {
            is_palindrome = false;
            break; // Saímos do loop assim que encontrarmos uma diferença
        }
        i++;
   }
   if (is_palindrome) {
        cout << word << " é um palíndromo." << endl;
   } else {
        cout << word << " não é um palíndromo." << endl;
   }

   return 0;
}
