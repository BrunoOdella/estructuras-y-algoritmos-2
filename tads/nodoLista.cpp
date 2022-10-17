#pragma once

template<class T>
class NodoLista {
    public:
        T dato;
        NodoLista<T> * sig;

        NodoLista(T dato): dato(dato), sig(NULL) {}
        NodoLista(T dato, NodoLista<T>* sig): dato(dato), sig(sig) {}
};