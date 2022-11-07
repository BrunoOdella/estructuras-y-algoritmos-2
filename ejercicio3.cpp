#include <iostream>
#include "tads/grafoListaAdy.cpp"
using namespace std;



int main(){
    int cantV;
    int cantA;
    cin >> cantV;
    cin >> cantA;
    Arista* aristas = new Arista[cantA];
    for (int i=0;i<=cantA;i++){
        int origen;
        cin >> origen;
        int destino;
        cin >> destino;
        int costo;
        cin >> costo;
        aristas[i].costo=costo;
        aristas[i].destino=destino;
        aristas[i].origen=origen;
    }
    GrafoLisAdy grafo(aristas, cantA, cantV);
//    kruskals(aristas, cantV);

}