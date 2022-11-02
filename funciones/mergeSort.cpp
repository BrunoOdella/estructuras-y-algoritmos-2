#include <iostream>
using namespace std;
//PRE:RECIBE UN VECTOR,INDICE DEL INICIO, MITAD Y FINAL   
//POS:CONVIERTE DOS LISTAS ORDENADAS EN UNA
void merge(int* vector,int* vector2, int ini, int m, int f)
{
	int izq = 0;
	int der = 0;
	int cont = ini;
	int l1 = m - ini + 1;
	int l2 = f - m;
	int* aux = new int[l1];
	int* aux2 = new int[l2];
    int* aux3 = new int[l1];
	int* aux4 = new int[l2];

	for (int i = 0; i < l1; i++)
	{
		aux[i] = vector[ini + i];
        aux3[i] = vector2[ini + i];
	}

	for (int i = 0; i < l2; i++)
	{
		aux2[i] = vector[m + 1 + i];
        aux4[i] = vector2[m + 1 + i];
	}

	while (izq < l1 && der < l2)
	{
		if (aux[izq] < aux2[der]) {
			vector[cont] = aux[izq];
            vector2[cont]= aux3[izq];
			izq++;
		}else if(aux[izq] == aux2[der]){
            if (aux3[izq] < aux4[der]){
                vector[cont] = aux[izq];
                vector2[cont]= aux3[izq];
			    izq++;

            }else {
                
            }

        }
		else
		{
			vector[cont] = aux2[der];
            vector2[cont] = aux4[der];
			der++;
		}
		cont++;
	}
	while (izq < l1)
	{
		vector[cont] = aux[izq];
        vector2[cont] = aux3[izq];
		cont++;
		izq++;
	}
	while (der < l2)
	{
		vector[cont] = aux2[der];
        vector2[cont] = aux4[der];
		cont++;
		der++;
	}
}

void division(int* vector,int* vector2, int ini, int fin)
{
	if (ini < fin)
	{
		int medio = ini + (fin - ini) / 2;
		//ini+(fin-ini)/2 es la posicion de la mitad
		//mitad izquierda
		division(vector,vector2, ini, medio);
		//mitad derecha
		division(vector,vector2, medio + 1, fin);
		//cuando termine la ultima division, comin
		merge(vector,vector2, ini, medio, fin);
	}
}

void ordenarVecIntMergeSort(int* vector,int* vector2, int largoVector)
{
	division(vector,vector2, 0, largoVector - 1);
}