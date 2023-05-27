#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

 using namespace std;

 int main()
 {
 int n,t,dado,total,v=1;

 cin>> t;

 while(t--)
 {
     cin>>n;
     total = 0;
     vector<int>dados;
     while(n--)
     {
        cin>>dado;
        dados.push_back(dado);
     }
     sort(dados.begin(),dados.end());

     for(vector<int>::iterator it = dados.begin(); it!=dados.end();++it)
        {
            if (total<*it)
                total++;
        }
    cout<<"Case #"<<v<<": "<<total<<endl;
    v++;
 }

 return 0;
 }

