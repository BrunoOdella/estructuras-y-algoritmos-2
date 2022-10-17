#include <iostream>
using namespace std;


template<class T>
void mostrarArray(T* array, int tope){
    cout << "[";
    for(int i=0; i<tope-1; i++){
        cout << array[i] << ", ";
    }
    cout << array[tope-1] << "]" << endl;
}