#include <iostream>
#include "tads/heap.cpp"
using namespace std;

int main(){
   
	int cantNum;
    cin >> cantNum;
    Heap h=crearHeap(cantNum);
    for (int i = 0; i < cantNum; i++) {
        int n;
		cin >> n;
        insertar(h,n,n);

	}
    for (int i=0;i<cantNum;i++){
        cout<< obtenerMin(h) <<endl;
        borrarMin(h);
    }
    return 0;

}