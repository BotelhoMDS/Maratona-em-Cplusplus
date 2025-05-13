#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int buscaLivro(int n, int capacidade, vector<int> &peso, vector<int> &interesse, vector<vector<int>> &bolsa)
{
    if (n==0  || capacidade == 0)
        return 0;
    if (bolsa[n][capacidade] >= 0)
        return bolsa[n][capacidade];
    if (peso[n-1] > capacidade)
        return bolsa[n][capacidade] = buscaLivro(n - 1, capacidade, peso, interesse,  bolsa);
    else
        return bolsa[n][capacidade] = max(buscaLivro(n - 1, capacidade, peso, interesse,  bolsa), buscaLivro(n - 1, capacidade - peso[n-1], peso, interesse,  bolsa) + interesse[n-1]);
}
int main(){
    int n, capacidade,caso = 1;
    while(cin >> n >> capacidade && (n!=0 && capacidade!=0))
    {
        vector<int> peso(n);
        vector<int> interesse(n);
        vector<vector<int>> bolsa(n+1, vector<int>(capacidade+1, -1));
        for (int i = 0; i < n; i++)
        {
            cin >> peso[i];
            cin >> interesse[i];
            //cout <<"peso "<<peso[0]<<" interesse "<<interesse[0]<<endl;
        }
        
        int maxInteresse = buscaLivro(n , capacidade, peso, interesse, bolsa);
        cout << "Caso " << caso++ << ": " << maxInteresse << endl;
    }



    return 0;
}