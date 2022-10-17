using namespace std;
#include <iostream>

typedef struct _RepresentacionHeap *Heap;

struct nodoHeap
{
    int dato;
    int prioridad;
};

nodoHeap *crearNodoH(int dato, int prioridad)
{
    nodoHeap *ret = new nodoHeap;
    ret->dato = dato;
    ret->prioridad = prioridad;
}

struct _RepresentacionHeap
{
    nodoHeap **heap;
    int largo;
    int tope;
};

Heap crearHeap(int largo)
{
    Heap ret = new _RepresentacionHeap;
    ret->largo = largo;
    ret->tope = 0;
    ret->heap = new nodoHeap *[largo];
    return ret;
}


void mostrar(Heap h)
{

    for (int i = 0; i < h->tope; i++)
    {
        cout << h->heap[i]->dato << endl;
    }
}

void flotar(Heap &h, int pos)
{
    while (  pos > 0 && (h->heap[((pos - 1) / 2)]->prioridad) > (h->heap[pos]->prioridad))
    { 

        int valorD = h->heap[((pos - 1) / 2)]->dato;
        int valorP = h->heap[((pos - 1) / 2)]->prioridad;
        h->heap[(pos - 1) / 2]->dato = h->heap[pos]->dato;
        h->heap[(pos - 1) / 2]->prioridad = h->heap[pos]->prioridad;
        h->heap[pos]->dato = valorD;
        h->heap[pos]->prioridad = valorP;

        // delete aux;
        pos = (pos - 1) / 2;
    }
    
}

void hundir(Heap &h, int pos)
{
    while (((2 * pos) + 1) < h->tope)
    {
        int hijoChico =2 * pos + 1;
        if (((2 * pos) + 2) < h->tope && h->heap[((2 * pos) + 2)]->prioridad < h->heap[((2 * pos) + 1)]->prioridad){
            hijoChico = ((2 * pos) + 2);
        }
        if (h->heap[pos]->prioridad < h->heap[hijoChico]->prioridad){
            break;
            }
            else{
            int auxD= h->heap[pos]->dato;
            int auxP= h->heap[pos]->prioridad;
            h->heap[pos]->dato = h->heap[hijoChico]->dato;
            h->heap[pos]->prioridad = h->heap[hijoChico]->prioridad;
            h->heap[hijoChico]->dato = auxD;
            h->heap[hijoChico]->prioridad = auxP;
            }
            pos = hijoChico;
    }
}

int cantidadElementos(Heap h)
{
    return h->tope;
}

bool esVacio(Heap h)
{
    return h->tope == 0;
}

bool esLleno(Heap h)
{
    return h->tope == h->largo;
}

void vaciar(Heap &h)
{
    while (h->tope > 0)
    {
        delete h->heap[--h->tope];
    }
}

void insertar(Heap &h, int dato, int prioridad)
{

    h->heap[h->tope++] = crearNodoH(dato, prioridad);
    flotar(h, h->tope - 1);
}

int obtenerMin(Heap h)
{
    return h->heap[0]->dato;
}

void borrarMin(Heap &h)
{
    h->heap[0] = h->heap[--h->tope];
    hundir(h, 0);
}



