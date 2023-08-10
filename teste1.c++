#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> escolherNumeros() {
    vector<int> numerosEscolhidos;
    
    cout << "Escolha os números de 1 a 6, um por vez:" << endl;
    
    for (int i = 1; i <= 6; i++) {
        int numero;
        cout << "Escolha número " << i << ": ";
        cin >> numero;
        
        if (numero < 1 || numero > 60) {
            cout << "Número fora do intervalo permitido. Escolha outro número." << endl;
            i--;
            continue;
        }
        
        if (find(numerosEscolhidos.begin(), numerosEscolhidos.end(), numero) != numerosEscolhidos.end()) {
            cout << "Número repetido. Escolha outro número." << endl;
            i--;
            continue;
        }
        
        numerosEscolhidos.push_back(numero);
    }
    
    return numerosEscolhidos;
}

int main() {
    bool sair = false;
    
    while (!sair) {
        vector<int> numerosEscolhidos = escolherNumeros();
        
        vector<int> numerosSorteados;
        srand(time(0));
        
        while (numerosSorteados.size() < 6) {
            int numero = rand() % 60 + 1;
            if (find(numerosSorteados.begin(), numerosSorteados.end(), numero) == numerosSorteados.end()) {
                numerosSorteados.push_back(numero);
            }
        }
        
        int acertos = 0;
        for (int numero : numerosEscolhidos) {
            if (find(numerosSorteados.begin(), numerosSorteados.end(), numero) != numerosSorteados.end()) {
                acertos++;
            }
        }
        
        cout << "Números sorteados: ";
        for (int numero : numerosSorteados) {
            cout << numero << " ";
        }
        cout << endl;
        
        if (acertos == 6) {
            cout << "Parabéns! Você acertou todos os números." << endl;
            cout << "Foram necessários " << numerosSorteados.size() << " sorteios para acertar." << endl;
        } else {
            cout << "Parabéns! Você acertou " << acertos << " números." << endl;
            cout << "Tente novamente." << endl;
        }
        
        cout << "Você deseja jogar novamente? (S/N) ";
        char opcao;
        cin >> opcao;
        
        if (opcao == 'N' || opcao == 'n') {
            sair = true;
        }
    }
    
    cout << "Obrigado por jogar!" << endl;
    
    return 0;
}