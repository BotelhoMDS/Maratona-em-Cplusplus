#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int buscaTabuas(int comprimento, int num_linhas, vector<int>& tabuas, vector<bool>& usadas) {
    int count = 0;
    int n = tabuas.size();
    
        
    for (int i = 0; i < n && num_linhas > 0; i++) {
         if (!usadas[i] && tabuas[i] == comprimento) {
            usadas[i] = true;
            count++;
            num_linhas--;
        }
        
        
        for (int j = i + 1; j < n && num_linhas && !usadas[i]  > 0; j++) {
            if (usadas[j]) continue;
            
            if (tabuas[i] + tabuas[j] == comprimento) {
                usadas[i] = usadas[j] = true;
                count += 2;
                num_linhas--;
                break;
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
        for (int i = 0; i < k; i++) {
            cin >> tabuas[i];
        }
        
        sort(tabuas.begin(), tabuas.end(), greater<int>());
        
        int resposta = -1;
        
        
        int linhas_m = (m * 100) / l;
        if ((m * 100) % l == 0) {
            vector<bool> usadas_m(k, false);
            int tabuas_m = buscaTabuas(n, linhas_m, tabuas, usadas_m);
            
            if (tabuas_m != -1) {
                resposta = tabuas_m;
            }
        }

        int linhas_n = (n * 100) / l;
        
        if ((n * 100) % l == 0) {
            vector<bool> usadas_n(k, false);
            int tabuas_n = buscaTabuas(m, linhas_n, tabuas, usadas_n);
            
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