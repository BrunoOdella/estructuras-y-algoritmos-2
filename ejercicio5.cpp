#include <iostream>
#include "tads/grafo.cpp"
#include "funciones/mergeSort.cpp"
using namespace std;

int main(){
    int cantV;
    int cantA;
    cin >> cantV;
    cin >> cantA;
    int* incidenciasVertices = new int [cantV];
    int * vertices = new int [cantV];
    for (int i=0;i<cantV;incidenciasVertices[i++]=0);
    for (int k=0;k<cantV;k++){
        vertices[k]=k+1;

    }
    for (int j=0;j<cantA;j++){
        int desde;
        int hasta;
        cin >>desde;
        cin >>hasta;
        incidenciasVertices[hasta-1]++;
    }

    ordenarVecIntMergeSort(incidenciasVertices,vertices,cantV);
   
    for (int i=cantV-1;i>-1;i--){
        cout << vertices[i] << " " << incidenciasVertices[i] << endl;
    }
    delete [] incidenciasVertices;
    delete [] vertices;





    
    




    return 0;
}