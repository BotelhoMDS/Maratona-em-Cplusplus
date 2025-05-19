#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int come_pipoca(long long tentativa, int t, int n,int c, vector<int>& pipocas) {
    int competidor = 1; 
    long long min_tempo = tentativa*t; 
    for (int i=0; i<n;i++)
    {
        if(min_tempo >= pipocas[i]){
            min_tempo -= pipocas[i]; 
        }
        else{
            competidor ++;
            min_tempo = t*tentativa;
            i--; 
        }
        if(competidor> c) return 0; 
    }
    return 1;
}
int main()
{
    int n,c,t, esquerda=1, direita = 1e9+10, meio; 
    vector<int> pipocas;
    cin >> n >> c >> t;
    for(int i=0;i<n;i++)
    {
        int a; 
        cin >> a; 
        pipocas.push_back(a); 
    }

    while(esquerda < direita)
    {
        meio = (esquerda + direita)/2; 
        if(come_pipoca(meio, t, n, c, pipocas)) direita = meio; 
        else esquerda = meio + 1; 
    }
    cout << esquerda << endl;
   

    return 0; 
}