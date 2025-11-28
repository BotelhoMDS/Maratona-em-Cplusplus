#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<utility>
#include<map>

using namespace std; 
using ll = long long;


int main()
{

    ll N,D; 
    while(cin>>N >>D)
    {
        if(!N && !D) break;
        string quadro;
        cin>>quadro; 
        vector<char> pilha; 
        ll removivel = D; 

        for(char digito : quadro)
        {
            while(!pilha.empty() && removivel>0 && pilha.back()< digito)
            {
                pilha.pop_back();
                removivel--;
            }
            pilha.push_back(digito);
        }
        while (removivel>0)
        {
            pilha.pop_back();
            removivel--;
        }
        string resultado (pilha.begin(), pilha.end());

        cout<<resultado<<endl;


    }
    return 0; 

}