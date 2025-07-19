#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

struct Aresta {
    int destino, peso;
    Aresta(int d, int p) : destino(d), peso(p) {}
};

void dfs(int v, const vector<vector<int>>& grafo, vector<bool>& visitado, stack<int>& pilha) {
    visitado[v] = true;
    for (int u : grafo[v]) {
        if (!visitado[u]) {
            dfs(u, grafo, visitado, pilha);
        }
    }
    pilha.push(v);
}

void dfs_scc(int v, const vector<vector<int>>& grafoT, vector<bool>& visitado, vector<int>& componente, int id) {
    visitado[v] = true;
    componente[v] = id;
    for (int u : grafoT[v]) {
        if (!visitado[u]) {
            dfs_scc(u, grafoT, visitado, componente, id);
        }
    }
}

vector<int> encontrar_scc(int N, const vector<vector<int>>& grafo, const vector<vector<int>>& grafoT) {
    vector<bool> visitado(N, false);
    stack<int> pilha;
    
    for (int i = 0; i < N; ++i) {
        if (!visitado[i]) {
            dfs(i, grafo, visitado, pilha);
        }
    }
    
    fill(visitado.begin(), visitado.end(), false);
    vector<int> componente(N, -1);
    int id = 0;
    
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();
        
        if (!visitado[v]) {
            dfs_scc(v, grafoT, visitado, componente, id);
            id++;
        }
    }
    
    return componente;
}

int dijkstra(int origem, int destino, const vector<vector<Aresta>>& grafo) {
    int N = grafo.size();
    vector<int> dist(N, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[origem] = 0;
    pq.push({0, origem});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const Aresta& aresta : grafo[u]) {
            int v = aresta.destino;
            int w = aresta.peso;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[destino];
}

int main() {
    
    
    int N, E;
    while (cin >> N >> E, N || E) {
        vector<vector<int>> grafo(N), grafoT(N);
        vector<vector<int>> pesos(N, vector<int>(N, INT_MAX));
        
        for (int i = 0; i < E; ++i) {
            int X, Y, H;
            cin >> X >> Y >> H;
            X--; Y--;
            grafo[X].push_back(Y);
            grafoT[Y].push_back(X);
            if (pesos[X][Y] > H) {
                pesos[X][Y] = H;
            }
        }
        
        vector<int> componente = encontrar_scc(N, grafo, grafoT);
        int num_componentes = *max_element(componente.begin(), componente.end()) + 1;
        
        vector<vector<Aresta>> grafo_condensado(num_componentes);
        
        for (int u = 0; u < N; ++u) {
            for (int v = 0; v < N; ++v) {
                if (pesos[u][v] != INT_MAX && componente[u] != componente[v]) {
                    grafo_condensado[componente[u]].emplace_back(componente[v], pesos[u][v]);
                }
            }
        }
        
        int K;
        cin >> K;
        
        while (K--) {
            int O, D;
            cin >> O >> D;
            O--; D--;
            
            if (componente[O] == componente[D]) {
                cout << "0\n";
            } else {
                int resultado = dijkstra(componente[O], componente[D], grafo_condensado);
                if (resultado == INT_MAX) {
                    cout << "Nao e possivel entregar a carta\n";
                } else {
                    cout << resultado << "\n";
                }
            }
        }
        
        cout << "\n";
    }
    
    return 0;
}