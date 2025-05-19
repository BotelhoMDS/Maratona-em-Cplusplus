#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


double min_distancia_fronteira(vector<pair<int,int>>& fronteira, double d)  
{
    double min_distancia = d;
    
    sort(fronteira.begin(), fronteira.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });
    
   
    for(int i = 0; i < fronteira.size(); i++)
    {
        for(int j = i+1; j < fronteira.size() && (fronteira[j].second - fronteira[i].second) < d; j++)
        {
            double distancia = sqrt(pow(fronteira[i].first - fronteira[j].first, 2) + 
                                  pow(fronteira[i].second - fronteira[j].second, 2));
            min_distancia = min(min_distancia, distancia);
        }
    }
    return min_distancia;
}

double min_distania(pair<int,int> coordenadas[], int inicio, int fim)  
{
    
    if(fim - inicio <= 3)
    {
        double min_distancia = 1e9;
        for(int i = inicio; i < fim; i++)
        {
            for(int j = i+1; j <= fim; j++)
            {
                double distancia = sqrt(pow(coordenadas[i].first - coordenadas[j].first, 2) + 
                                       pow(coordenadas[i].second - coordenadas[j].second, 2));
                min_distancia = min(min_distancia, distancia);
            }
        }
        return min_distancia;
    }
    
    int meio = (inicio + fim) / 2;
    double desq = min_distania(coordenadas, inicio, meio);
    double ddir = min_distania(coordenadas, meio + 1, fim);
    double d = min(desq, ddir);
    
   
    int ponto_central = coordenadas[meio].first;
    vector<pair<int,int>> fronteira;
    for(int i = inicio; i <= fim; i++)
    {
        if(abs(coordenadas[i].first - ponto_central) < d)
        {
            fronteira.push_back(coordenadas[i]);
        }
    }

    
    double d_fronteira = min_distancia_fronteira(fronteira, d);

    
    return min(d, d_fronteira);  
}

int main()
{
    int n;
    while(cin >> n && n != 0)  
    {
        pair<int,int> coordenadas[n];
        double resposta;  
        
        for(int i = 0; i < n; i++)
        {
            cin >> coordenadas[i].first >> coordenadas[i].second;
        }
         if (n < 2) {
            cout << "INFINITY"<<endl;
            continue;
        }
        
        
        sort(coordenadas, coordenadas + n, [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        });


        resposta = min_distania(coordenadas, 0, n - 1);

        if(resposta < 10000.0000) 
            printf("%.4lf\n", resposta);  
        else 
            cout << "INFINITY" << endl;
    }
    return 0;
}