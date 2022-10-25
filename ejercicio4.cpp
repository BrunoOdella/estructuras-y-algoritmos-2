#include <iostream>
#include "tads/grafo.cpp"
using namespace std;

int main(){
    int cantV;
    int cantA;
    cin >> cantV;
    cin >> cantA;
    Grafo *g= new Grafo(cantV,true);
    for (int i=1;i<=cantV;i++){
        g->insertarVertice(i);
    }
    for( int j=0;j<cantA;j++){
        int origen;
        cin >> origen;
        int destino;
        cin >> destino;
        g->insertarArista(origen,destino,1);

    }
    if (g->esTriconexo()){
        cout << "1" << endl;
    }else {
        cout << "0" << endl;
    }

    return 0;

}