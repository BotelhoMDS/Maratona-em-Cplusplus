#include<iostream>
#include <vector>
#include<fstream>
#include<cstring>

using namespace std;

int main ()
{
    char mineradora [1010];
    int verifica =0, diamante=0,n,j=0;
    scanf ("%d", &n);
    for (int i =0; i<n; i++)
    {
        scanf("%s", &mineradora);

        while (mineradora[j] != ' ')
        {
            if (mineradora[j] == '<')
            {
                mineradora[j] = ' ';
                verifica ++;
            }
            if (mineradora[j] == '>')
            {
                mineradora[j] = ' ';
                if (verifica>0)
                {
                    diamante++;
                    verifica--;
                }
            }
            j++;
        }
        printf("%d\n",diamante);
         verifica = 0;
         diamante=0;
         j=0;
    }
return 0;
}
