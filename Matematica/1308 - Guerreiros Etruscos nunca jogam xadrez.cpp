#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main ( )
{
    int M;
    long long N =0;


    scanf("%d",&M);
    while (M--)
    {
        cin>>N;
        N = ((sqrt(1+8*N)-1))/2;
        cout<<N<<endl;
    }


    return 0;
}
