#include <iostream>
#include <stdlib.h>


using namespace std;

int main() {

    string resposta;
    int X, Y;
    scanf ("%d %d", &X, &Y);
    while (X!=Y)
    {

    resposta = (X>Y)?"Decrescente":"Crescente";
    cout<< resposta<<endl;
     scanf ("%d %d", &X, &Y);
    }

    return 0;
}
