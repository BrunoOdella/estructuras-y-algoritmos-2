#include <iostream>
#include "tads/arrays.cpp"
using namespace std;



int numeroSinPareja(int*& arreglo, int desde, int hasta){
    
    if (desde==hasta){
        return arreglo[hasta];
    }
    if (((desde + hasta)/2)%2 != 0 ){
        if (arreglo[(desde + hasta)/2] == arreglo[((desde + hasta)/2)-1]){
            numeroSinPareja(arreglo,((desde + hasta)/2)+1,hasta);

        }else {
             numeroSinPareja(arreglo,desde,((desde + hasta)/2)-1);
        }
       
    }else {
        if (arreglo[(desde + hasta)/2] == arreglo[((desde + hasta)/2)+1] ){
            numeroSinPareja(arreglo,((desde + hasta)/2)+2,hasta);
        }else{
            numeroSinPareja(arreglo,desde,((desde + hasta)/2));
        }
    }


    
}
int main(){
    int cantElem, valor;
    cin >> cantElem;
    int* arreglo=new int[cantElem];
    for (int i = 0; i < cantElem; i++)
    {
        cin >> valor;
        arreglo[i]=valor;
    }
   
    cout << numeroSinPareja(arreglo,0,cantElem-1) << endl;
    delete [] arreglo;
    return 0;

}
    
    


    

