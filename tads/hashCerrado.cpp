#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct _RepresentacionTablaHashCerrado *TablaHashCerrado;

struct _RepresentacionTablaHashCerrado
{
	string *tabla;
	int cantElem;
	int largoVec;
};

// FUNCION DE HORNER SACADA DE INTERNET-ROBEDWARDS EN YOUTUBE
long long horner(string pal)
{
	int x = 31;

	long long ret = 0;
	for (int i = 0; i < pal.length(); i++)
	{
		if (pal[i] != '@' && pal[i] != '.')
		{
			ret = x * ret + (int)pal[i];
		}
		if (ret < 0)
		{
			ret = ret + 9223372036854775807;
		}
	}

	return ret;
}
int miHash(int largo, string pal)
{

	long long ret = horner(pal);
	ret = ret % largo;
	return ret;
	
}

// PRE: RECIBE UN NUMERO
//  POS : DEVUEVLO TRUE SI ES PRIMO
bool esPrimo(int num)
{
	if (num < 2 || (num % 2 == 0 && num > 2))
	{
		return false;
	}
	for (int i = 3; i < num / 2; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int proximoPrimo(int num)
{
	// for(num=num+1; !esPrimo(num); num++);
	while (!esPrimo(++num))
		;
	return num;
}

TablaHashCerrado crearTabla(int n)
{
	int tamano = proximoPrimo(n * 2);
	TablaHashCerrado nueva = new _RepresentacionTablaHashCerrado;
	nueva->tabla = new string[tamano];
	nueva->largoVec = tamano;
	nueva->cantElem = 0;
	return nueva;
}

void agregar(TablaHashCerrado &t, string correo)
{
	int pos = miHash(t->largoVec, correo);

	while (t->tabla[pos] != "")
	{
		if (t->tabla[pos].compare(correo) == 0)
		{

			return;
		}
		else
		{
			pos = ((pos + 1) % t->largoVec);
		}
	}

	t->tabla[pos] = correo;
	t->cantElem++;
}
int correosUnicos(TablaHashCerrado t)
{
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
