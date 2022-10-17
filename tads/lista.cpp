#pragma once

#include "iostream"
#include "nodoLista.cpp"
#include "iteradorLista.cpp"
using namespace std;

template <class T>
class Lista
{
private:
  NodoLista<T> *ppio, *fin;
  int cant;

  void vaciarRec(NodoLista<T> *&l)
  {
    if (l)
    {
      vaciarRec(l->sig);
      delete l;
      l = NULL;
    }
  }

  bool existeRec(T dato, NodoLista<T>* nodo){
    return nodo!=NULL && (dato == nodo->dato || existeRec(dato, nodo->sig));
  }

public:
  Lista()
  {
    ppio = fin = NULL;
    cant = 0;
  }

  ~Lista()
  {
    vaciarRec(ppio);
  }

  void vaciar(){
    vaciarRec(ppio);
  }

  bool esVacia()
  {
    return cant == 0;
  }

  int largo()
  {
    return cant;
  }

  void insertarPpio(T dato)
  {
    ppio = new NodoLista<T>(dato, ppio);
    if (!fin)
    {
      fin = ppio;
    }
    cant++;
  }

  void insertarFin(T dato)
  {
    if (!fin)
    {
      fin = ppio = new NodoLista<T>(dato);
    }
    else
    {
      fin->sig = new NodoLista<T>(dato);
      fin = fin->sig;
    }
    cant++;
  }

  void insertarOrd(T dato, int (*fComp)(T a, T b)){
    if(!ppio || fComp(dato, ppio->dato)<=0){
      insertarPpio(dato);
    } else {
      NodoLista<T>* aux = ppio;
      while(aux->sig && fComp(dato, aux->sig->dato)>0){
        aux = aux->sig;
      }
      aux->sig = new NodoLista<T>(dato, aux->sig);
      if(fin->sig){
        fin=fin->sig;
      }
      cant++;
    }
  }

  // Pre: !esVacia()
  T obtenerPpio()
  {
    return ppio->dato;
  }

  // Pre: !esVacia()
  T obtenerFin()
  {
    return fin->dato;
  }

  void borrarPpio()
  {
    NodoLista<T> *aBorrar = ppio;
    ppio = ppio->sig;
    delete aBorrar;
    if (!ppio)
    {
      fin = NULL;
    }
    cant--;
  }

  bool existe(T dato){
    return existeRec(dato, ppio);
  }

  IteradorLista<T>* obtenerIterador(){
      return new IteradorLista<T>(ppio);
  }
};