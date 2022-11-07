#include <iostream>
#include "nodoListaDobleDato.cpp"
#include "arrays.cpp"
#define INF 99999
using namespace std;

struct Arista {
    int origen, destino, costo;
};

class GrafoLisAdy
{
    NodoListaDobleDato* ObtenerNodoListaAdy(int valor, int costo, NodoListaDobleDato* cabezal){
        NodoListaDobleDato* nuevo=new NodoListaDobleDato;
        nuevo->costo=costo;
        nuevo->dato=valor;
        nuevo->sig=cabezal;
    }
    int cantVertices;

public:
    NodoListaDobleDato** cabezal;
    GrafoLisAdy(Arista* aristas,int n, int cantVertices){
            cabezal=new NodoListaDobleDato* [cantVertices]();
            this->cantVertices= cantVertices;
            for (int i = 0; i < cantVertices; i++)
            {
                cabezal[i] = NULL;
            }
            for (int i = 0; i < n; i++)
            {
                NodoListaDobleDato* nuevo = ObtenerNodoListaAdy(aristas[i].destino,aristas[i].costo, cabezal[aristas[i].origen-1]);
                cabezal[aristas[i].origen]=nuevo;
            }
    }
};
    
class UnionFind {

    int* id, *sz;

     UnionFind(int n) {
      id = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
      }
    }

    int find(int p) {
      int root = p;
      while (root != id[root]) root = id[root];
      while (p != root) { 
        int next = id[p];
        id[p] = root;
        p = next;
      }
      return root;
    }

    bool connected(int p, int q) {
      return find(p) == find(q);
    }

    int size(int p) {
      return sz[find(p)];
    }

    void unionF(int p, int q) {
      int root1 = find(p);
      int root2 = find(q);
      if (root1 == root2) return;
      if (sz[root1] < sz[root2]) {
        sz[root2] += sz[root1];
        id[root1] = root2;
      } else {
        sz[root1] += sz[root2];
        id[root2] = root1;
      }
    }
  

    void kruskals(NodoListaDobleDato* aristas, int n) {

    if (aristas==NULL) return;

    int sum = 0;
    UnionFind* uf = new UnionFind(n);

    for (int i=0; i<n; i++) {

      // Skip this edge to avoid creating a cycle in MST

      if (connected(i+1,aristas[i].dato)) continue;

      // Include this edge
      unionF(i+1,aristas[i].dato);

      cout << i+1 << aristas[i].dato << aristas[i].costo  << endl;;

      // Optimization to stop early if we found
      // a MST that includes all the nodes
      if (size(0) == n) break;
    }

    // Make sure we have a MST that includes all the nodes
    if (size(0) != n) return;

    return ;
  }
};
