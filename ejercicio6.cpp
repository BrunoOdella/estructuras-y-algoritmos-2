#include <iostream>
#include "tads/arrays.cpp"
using namespace std;

int main(){
    int cantElem, valor;
    cin >> cantElem;
    int* arreglo=new int[cantElem]();
    for (int i = 0; i < cantElem; i++)
    {
        cin >> valor;
        arreglo[i]=valor;
    }

}

int numeroSinPareja(int*& arreglo, int cantElem, int pos){

    if ((!arreglo[pos+1] || !arreglo[pos-1]) || (arreglo[pos]!=arreglo[pos+1] && arreglo[pos]!=arreglo[pos-1]))
    {
        return arreglo[pos];
    }
    //COSTADOS PARES?
    if((cantElem-1/2)%2==0){
        if (arreglo[pos-1]!= arreglo[pos])
        {
            numeroSinPareja(arreglo,cantElem+1/2,pos+pos/2);
        }else
        {
            numeroSinPareja(arreglo,cantElem+1/2,pos-pos/2);
        }     
    }else
    {
    //COSTADOS IMPARES
        if (arreglo[pos-1]!= arreglo[pos])
        {
            numeroSinPareja(arreglo,cantElem-1/2,pos-pos/2-1);
        }else
        {
            numeroSinPareja(arreglo,cantElem-1/2,pos+pos/2+1);
        } 
    }
    
    


    
}
