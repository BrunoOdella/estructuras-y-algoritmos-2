#include <iostream>
using namespace std;
#define INF 99999
#include "tads/arrays.cpp"

void subconjDeSuma(int m, int *conjunto, int cantNumeros, int pos,
                   int valorActual, int *&solActual, int &valorOptimo, int *&solOptima)
{

  if (m == 0 || pos == cantNumeros)
  {
    if (m == 0 && valorActual < valorOptimo)
    {
      valorOptimo = valorActual;
      for (int i = 0; i < cantNumeros; solOptima[i] = solActual[i++])
        ;
    } 
  }
 
  else if (valorActual < valorOptimo)
  {
    int vecesPosibles = m / conjunto[pos];
    for (int k = 0; k <= vecesPosibles; k++)
    {
      solActual[pos] = k;
      subconjDeSuma(m - k * conjunto[pos], conjunto, cantNumeros, pos + 1,
                    valorActual + k, solActual, valorOptimo, solOptima);
    }
    solActual[pos] = 0;
  
}
}

int main()
{

  int cantNumeros;
  cin >> cantNumeros;
  int *conjunto = new int[cantNumeros];
  for (int i = 1; i <= cantNumeros; i++)
  {

    cin >> conjunto[i - 1];
  }

  int p;
  cin >> p;
  int *numerosM = new int[p];
  for (int i = 1; i <= p; i++)
  {
    int m;

    cin >> m;
    numerosM[i - 1] = m;
  }

  int *solActual = new int[cantNumeros];
  for (int i = 0; i < cantNumeros; solActual[i++] = 0)
    ;
  int *solOptima = new int[cantNumeros];
  int valorActual = 0, pos = 0, valorOptimo = INF;
  // BUCLE PARA TODOS LOS VALORES M
  for (int i = 0; i < p; i++)
  {
    subconjDeSuma(numerosM[i], conjunto, cantNumeros, pos, valorActual, solActual, valorOptimo, solOptima);
    if (valorOptimo != INF)
    {
      cout << valorOptimo << endl;
      
    }
    else
    {
      cout << "0" << endl;
    }
    for (int i = 0; i < cantNumeros; solActual[i++] = 0)
      ;
    valorOptimo = INF;
  }

  return 0;
}