#include <iostream>
#include "tads/hashCerrado.cpp"
using namespace std;

int main(){
   
	int cantCorreos;
    cin >> cantCorreos;
    TablaHashCerrado registro= crearTabla(cantCorreos);
    for (int i = 0; i < cantCorreos; i++) {
        string correo;
		cin >> correo;
        agregar(registro,correo);

	}
	cout<< correosUnicos(registro) <<endl;
    return 0;

}





