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

// Usei a LLM para consultar se o map já incia seus valores internos com 0 e como iterar sobre o map

int main()
{
    long long N; 
    while (cin>>N)
    {
        map<long long,long long> job; 
        long long d,p; 
        for(int i=0; i<N;i++)
        {
            cin>> d>>p; 
            job[d] +=p;          
            
        }
        long long t = 1; 
        for( const auto& valor : job)
        {
            (valor.first <= t)? t += valor.second : t += (valor.first - t)+ valor.second;

        }
        cout<<t<<endl;
    }
    return 0; 
}