#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<utility>
#include<map>
// Código do merge sort adaptado do https://www.geeksforgeeks.org/dsa/merge-sort/
using namespace std; 
using ll = long long;

ll merge_count(vector<string>& arr, int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    vector<string> L(n1), R(n2);

    
    for (int i = 0; i < n1; i++)
        L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    ll inv_count = 0;

    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inv_count += (n1 - i);  
        }
        k++;
    }

    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    } 
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inv_count;
}


ll mergeSort_count(vector<string>& arr, int esq, int dir) {
    if (esq >= dir) return 0;

    int meio = esq + (dir - esq) / 2;
    ll inv = 0;

    inv += mergeSort_count(arr, esq, meio);
    inv += mergeSort_count(arr, meio + 1, dir);
    inv += merge_count(arr, esq, meio, dir);

    return inv;
}

int main()
{
     int N;
    while (cin >> N) {

        vector<string> rank(N);
        for (int i = 0; i < N; i++)
        {
            cin >> rank[i];
        }
            

        
        cout << mergeSort_count(rank, 0, N - 1) << endl;
    }



    return 0; 
}