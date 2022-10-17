#include <iostream>
#include <string>

using namespace std;

typedef struct _RepresentacionTablaHashCerrado *TablaHashCerrado;

struct _RepresentacionTablaHashCerrado{
	string* tabla;
	int cantElem;
	int largoVec;
};

int miHash(int largo,string pal){
	int x=31;
	int ret=0;
	for (int i=0; i<pal.length();i++){
		if (ret<2^10){
		ret=x*ret + pal[i];
		}else{
			ret=ret%largo;
		}
	}
	return ret%largo;
	//return n%largo;
}
//FUNCION DE HORNER SACADA DE INTERNET-ROBEDWARDS EN YOUTUBE
long long horner (string pal){
	int x=31;
	long long ret=0;
	for (int i=0; i<pal.length();i++){
		ret=x*ret + pal[i];
	}
	return ret;
}
//PRE: RECIBE UN NUMERO
// POS : DEVUEVLO TRUE SI ES PRIMO 
bool esPrimoo(int n) {

	if (n <= 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


//PRE: RECIBE UN NUMERO
// POS : DEVUEVLO EL PRIMO MAYOR  MAS PROXIMO A EL 
int proximoPrimo(int n) {
	int ret = n;
	bool encontre = false;
	for (int i = n; !encontre; i++) {
		if (esPrimoo(i)) {
			ret = i;
			encontre = true;


		}
	}
	return ret;
}


TablaHashCerrado crearTabla (int n){
	int tamano=proximoPrimo(n*2);
    TablaHashCerrado nueva = new _RepresentacionTablaHashCerrado;
    nueva->tabla= new string[tamano];
	nueva->largoVec=tamano;
	nueva->cantElem=0;
	return nueva;
}

void agregar(TablaHashCerrado &t, string correo){
	int pos=miHash(t->largoVec,correo);
	while (t->tabla[pos]!=""){
		if (t->tabla[pos].compare(correo)==0){
			
			return;
		}else{
			pos=((pos+1)%t->largoVec);
		}
	}
	
	t->tabla[pos]=correo;
	t->cantElem++;

}
int correosUnicos(TablaHashCerrado t){
	return t->cantElem;
}
/*int main (){
	TablaHashCerrado nueva= crearTabla(10);
	agregar(nueva,"bruno@hotmail.com");
	agregar(nueva,"bruno@hotmail.com");
	agregar(nueva,"bruno1@hotmail.com");
	agregar(nueva,"abc");
	int ret=correosUnicos(nueva);
	cout << ret << endl;
	//cout << nueva->largoVec << endl;

}
*/






