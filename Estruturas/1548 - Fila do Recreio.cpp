#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

void troca (int *J1, int *J2)
{
    int aux = *J1;
    *J1 = *J2;
    *J2 = aux;
}


void ordena(int F1[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (F1[j] < F1[j+1])
            troca(&F1[j], &F1[j+1]);
}




int main ()
{
int i,cont,N, M, fila[1010], fila2[1010];

scanf(" %d",&N);


while (N>0){
        cont = 0;
        scanf("%d",&M);

for (i=0; i<M; i++) // entra com as filas e duplica para a fila de conferencia
{

    scanf("%d",&fila[i]);
    fila2[i]=fila[i];
}

ordena(fila,M);




for(i=0; i<M; i++)  // verifica se a posições iguais nas filas
{


    if (fila[i]==fila2[i]){
        cont++;
    }

}

printf("%d\n", cont);

N--;
}
return 0;
}
