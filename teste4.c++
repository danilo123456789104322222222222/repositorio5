// Alunos: Danilo Alves e Sebastião Marques

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;   

// Função para escolher números
vector<int> escolherNumeros() {
    vector<int> numerosEscolhidos;
    
    cout << "Escolha os numeros de 1 a 60, um por vez:" << endl;
    
    for (int i = 1; i <= 6; i++) {
        int numero;
        cout << "Escolha numero " << i << ": ";
        cin >> numero;
        
        if (numero < 1 || numero > 60) {
            cout << "Numero fora do intervalo permitido. Escolha outro numero." << endl;
            i--;
           continue;
        }
        
        if (find(numerosEscolhidos.begin(), numerosEscolhidos.end(), numero) != numerosEscolhidos.end()) {
            cout << "Numero repetido. Escolha outro numero." << endl;
            i--;
            continue;
        }
        
        numerosEscolhidos.push_back(numero);
    }
    
    return numerosEscolhidos;
}

// Função principal
int main() {
    bool sair = false;
    
    while (!sair) {
        vector<int> numerosEscolhidos = escolherNumeros();
        
        vector<int> numerosSorteados;
        srand(time(0));
        
        // Sorteio de números aleatórios
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
        
        // Exibição de resultados
        cout << "Numeros sorteados: ";
        for (int numero : numerosSorteados) {
            cout << numero << " ";
        }
        cout << endl;
        
        if (acertos == 6) {
            cout << "Parabens! Voce acertou todos os numeros." << endl;
            cout << "Foram necessarios " << numerosSorteados.size() << " sorteios para acertar." << endl;
        } else {
            cout << "Parabens! Você acertou " << acertos << " numeros." << endl;
            cout << "Tente novamente." << endl;
        }
        
        // Pergunta sobre jogar novamente
        cout << "Voce gostaria de jogar novamente? (S/N) ";
        char opcao;
        cin >> opcao;
        
        if (opcao == 'N' || opcao == 'n') {
            sair = true;
        }
    }
    
    cout << "Obrigado por jogar o Mega Senai!" << endl;
    
    return 0;
}