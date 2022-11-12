#include <iostream>
#include <string>
using namespace std;
// COMPARADOR DE CARCATER A CARACTER, EL MAS QUE TENGA EL DIGITO MAS GRANDE VA PRIMERO, SI AMBOS SON IGUALES PONE EL QUE TENGA MENOS DIGITOS
int comparador(string a, string b)
{
  int hasta = min(a.length(), b.length());

  if (a == b)
  {
    return 1;
  }

  for (int i = 0; i < hasta; i++)
  {
    if (a[i] < b[i])
    {
      return -1;
    }
    else if (a[i] > b[i])
    {
      return 1;
    }
  }

  if (a[a.length() - 1] < b[b.length() - 1])
  {
    return -1;
  }
  else
  {
    return 1;
  }
}


int main()
{
  // CARGO LOS DATOS
  int n;
  cin >> n;
  int largo = n;
  string *vec = new string[n];
  for (int i = 0; i < n; i++)
  {
    string num;
    cin >> num;
    vec[i] = num;
  }
  for (int i = 0; i < largo; i++)
  {
  }

  string ret;
  // BUBBLE SORT CON EL COMPARADOR
  for (int i = 0; i < largo - 1; i++)
  {
    for (int j = 0; j < largo - 1; j++)
    {
      string n1 = vec[j];
      string n2 = vec[j + 1];
      int comparacion = comparador(n1, n2);
      if (comparacion == -1)
      {
        string aux = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = aux;
      }
    }
  }

  for (int i = 0; i < largo; i++)
  {

    ret.append(vec[i]);
  }
  cout << ret << endl;

  return 1;
}
