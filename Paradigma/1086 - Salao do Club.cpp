#include <iostream>
#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int buscaTabuas(int comprimento, int num_linhas, vector<int>& tabuas, unordered_map<int, int>& estoque_global) {
    unordered_map<int, int> estoque = estoque_global;
    int count = 0;
    
    
    if (estoque.count(comprimento)) {
        int usar = min(estoque[comprimento], num_linhas);
        count += usar;
        num_linhas -= usar;
        estoque[comprimento] -= usar;
        if (estoque[comprimento] == 0) {
            estoque.erase(comprimento);
        }
    }
    
    
    if (num_linhas > 0) {
        auto it = estoque.begin();
        while (it != estoque.end() && num_linhas > 0) {
            int tabua = it->first;
            int complemento = comprimento - tabua;
            
            if (complemento < tabua) {  
                ++it;
                continue;
            }
            
            if (complemento == tabua) {
                int pares = it->second / 2;
                int usar = min(pares, num_linhas);
                count += usar * 2;
                num_linhas -= usar;
                it->second -= usar * 2;
                if (it->second <= 0) {
                    it = estoque.erase(it);
                } else {
                    ++it;
                }
            } else if (estoque.count(complemento)) {
                int pares = min(it->second, estoque[complemento]);
                int usar = min(pares, num_linhas);
                count += usar * 2;
                num_linhas -= usar;
                estoque[complemento] -= usar;
                if (estoque[complemento] <= 0) {
                    estoque.erase(complemento);
                }
                it->second -= usar;
                if (it->second <= 0) {
                    it = estoque.erase(it);
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
    }
    
    return (num_linhas == 0) ? count : -1;
}

int main() {
    int m, n, l, k;
    
    while (cin >> m >> n , m || n) {
        cin >> l >> k;
        vector<int> tabuas(k);
        unordered_map<int, int> estoque;
        for (int i = 0; i < k; i++) {
            cin >> tabuas[i];
            tabuas[i] = tabuas[i];
            estoque[tabuas[i]]++;

        }
        
        int resposta = -1;
        

        int linhas_m = (m * 100) / l;
        if ((m * 100) % l == 0) {
            int tabuas_m = buscaTabuas(n, linhas_m, tabuas,estoque);
            if (tabuas_m != -1) {
                resposta = tabuas_m;
            }
        }

        int linhas_n = (n * 100) / l;
        if ((n * 100) % l == 0) {
            int tabuas_n = buscaTabuas(m, linhas_n, tabuas,estoque);
            if (tabuas_n != -1 && (resposta == -1 || tabuas_n < resposta)) {
                resposta = tabuas_n;
            }
        }
        
        if (resposta != -1) {
            cout << resposta << endl;
        } else {
            cout << "impossivel" << endl;
        }
    }
    
    return 0;
}