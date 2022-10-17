#include <iostream>
#include "lista.cpp"
#include "arrays.cpp"
#define INF 99999
using namespace std;

class Arista
{
public:
    int origen, destino;
    int costo;
    bool existe;

    Arista(int origen, int destino, int costo) : origen(origen), destino(destino), costo(costo), existe(true){};
    Arista(int origen, int destino) : origen(origen), destino(destino), costo(0), existe(false){};
};

int fCompArista(Arista *a, Arista *b)
{
    return a->costo - b->costo;
}

class Grafo
{
private:
    bool esDirigido;
    int tope;
    int cantVertices;
    int **vertices;
    Arista ***matAdy;
    Lista<int> *listaHuecos;

    int posVertice(int vert)
    {
        for (int i = 0; i < tope; i++)
        {
            if (this->vertices[i] != NULL && *this->vertices[i] == vert)
            {
                return i;
            }
        }
        return -1;
    }

    int posOcupada()
    {
        for (int i = 0; i < tope; i++)
        {
            if (this->vertices[i] != NULL)
            {
                return i;
            }
        }
        return -1;
    }

    void DFSRec(int pos, bool *vis)
    {
        cout << *this->vertices[pos] << endl;
        vis[pos] = true;
        for (int j = 0; j < tope; j++)
        {
            if (!vis[j] && this->matAdy[pos][j]->existe)
            {
                DFSRec(j, vis);
            }
        }
    }

    int posNoVisMasCercano(int *dist, bool *vis)
    {
        int posMin = -1, min = INF;
        for (int i = 0; i < tope; i++)
        {
            if (!vis[i] && dist[i] < min)
            {
                posMin = i;
                min = dist[i];
            }
        }
        return posMin;
    }
    int posNoVis(bool *vis)
    {

        for (int i = 0; i < tope; i++)
        {
            if (!vis[i])
            {
                return i;
            }
        }
    }

    bool esConexo(int i, int j, int cantEsperada)
    {
        bool *vis = new bool[tope];
        int cantVert = 0;
        for (int i = 0; i < tope; vis[i++] = false);
        vis[i] = true;
        vis[j] = true;
        int posOrigen = posNoVis(vis);
        Lista<int> *cola = new Lista<int>();
        cola->insertarFin(posOrigen);
        while (!cola->esVacia())
        {
            int pos = cola->obtenerPpio();
            cola->borrarPpio();
            cout << *this->vertices[pos] << endl;
            vis[pos] = true;
            cantVert++;
            for (int j = 0; j < tope; j++)
            {
                if (!vis[j] && this->matAdy[pos][j]->existe)
                {
                    cola->insertarFin(j);
                    vis[j] = true;
                }
            }
        }
        cout << "-------" << endl;
        return cantVert == cantEsperada;
    }

public:
    Grafo(int tope, bool esDirigido)
    {
        this->tope = tope;
        this->esDirigido = esDirigido;
        this->cantVertices = 0;
        this->vertices = new int *[tope];
        for (int i = 0; i < tope; vertices[i++] = NULL)
            ;

        this->matAdy = new Arista **[tope];
        if (esDirigido)
        {
            for (int i = 0; i < tope; i++)
            {
                this->matAdy[i] = new Arista *[tope];
                for (int j = 0; j < tope; j++)
                {
                    this->matAdy[i][j] = new Arista(i, j);
                }
            }
        }
        else
        {
            for (int i = 0; i < tope; i++)
            {
                this->matAdy[i] = new Arista *[tope];
            }
            for (int i = 0; i < tope; i++)
            {
                for (int j = i; j < tope; j++)
                {
                    this->matAdy[i][j] = this->matAdy[j][i] = new Arista(i, j);
                }
            }
        }

        this->listaHuecos = new Lista<int>();
        for (int k = 0; k < tope; k++)
        {
            this->listaHuecos->insertarFin(k);
        }
    }

    void insertarVertice(int vert)
    {
        int hueco = this->listaHuecos->obtenerPpio();
        this->listaHuecos->borrarPpio();

        this->vertices[hueco] = new int(vert);
        this->cantVertices++;
    }

    void insertarArista(int origen, int destino, int costo)
    {
        int posOrigen = posVertice(origen);
        int posDestino = posVertice(destino);

        Arista *arista = this->matAdy[posOrigen][posDestino];
        arista->costo = costo;
        arista->existe = true;
    }

    void ordenTopologico()
    {

        Lista<int> *bolsaCeros = new Lista<int>();
        // Calculo vector de grados de incidencia de los vértices
        int *gradosIncidencia = new int[tope];
        for (int k = 0; k < tope; k++)
        {
            gradosIncidencia[k] = 0;
        }
        for (int j = 0; j < tope; j++)
        {
            if (vertices[j] == NULL)
            {
                continue;
            }
            for (int i = 0; i < tope; i++)
            {
                if (this->matAdy[i][j]->existe)
                {
                    gradosIncidencia[j]++;
                }
            }
            if (gradosIncidencia[j] == 0)
            {
                bolsaCeros->insertarFin(j);
            }
        }
        for (int k = 0; k < cantVertices; k++)
        {
            if (bolsaCeros->esVacia())
            {
                cout << "CICLOOOOOO!" << endl;
                return;
            }
            int vert = bolsaCeros->obtenerPpio();
            bolsaCeros->borrarPpio();
            cout << *this->vertices[vert] << endl;
            for (int j = 0; j < tope; j++)
            {
                if (this->matAdy[vert][j]->existe)
                {
                    gradosIncidencia[j]--;
                    if (gradosIncidencia[j] == 0)
                    {
                        bolsaCeros->insertarFin(j);
                    }
                }
            }
        }
    }

    // Depth-First Search
    void DFS(int origen)
    {
        int posOrigen = posVertice(origen);
        bool *vis = new bool[tope];
        for (int i = 0; i < tope; vis[i++] = false)
            ;
        DFSRec(posOrigen, vis);
    }

    // Breadth-First Search
    void BFS(int origen)
    {
        int posOrigen = posVertice(origen);
        bool *vis = new bool[tope];
        for (int i = 0; i < tope; vis[i++] = false)
            ;
        Lista<int> *cola = new Lista<int>();
        cola->insertarFin(posOrigen);
        while (!cola->esVacia())
        {
            int pos = cola->obtenerPpio();
            cola->borrarPpio();
            cout << *this->vertices[pos] << endl;
            vis[pos] = true;
            for (int j = 0; j < tope; j++)
            {
                if (!vis[j] && this->matAdy[pos][j]->existe && !cola->existe(j))
                {
                    cola->insertarFin(j);
                    //vis[j] = true;
                }
            }
        }
    }

    void dijkstra(int origen)
    {
        int posOrigen = posVertice(origen);

        bool *vis = new bool[tope];
        int *dist = new int[tope];
        int *ant = new int[tope];

        for (int i = 0; i < tope; vis[i] = false, dist[i] = INF, ant[i] = -1, i++)
            ;
        dist[posOrigen] = 0;

        for (int k = 0; k < cantVertices; k++)
        {
            int proxVertice = posNoVisMasCercano(dist, vis);

            if (proxVertice == -1)
            {
                break;
            }
            vis[proxVertice] = true;
            for (int j = 0; j < tope; j++)
            {
                if (!vis[j] && matAdy[proxVertice][j]->existe)
                {
                    int nuevaDist = dist[proxVertice] + matAdy[proxVertice][j]->costo;
                    if (nuevaDist < dist[j])
                    {
                        dist[j] = nuevaDist;
                        ant[j] = proxVertice;
                    }
                }
            }
        }
        cout << "Dist" << endl;
        mostrarArray(dist, tope);
        cout << "Ant" << endl;
        mostrarArray(ant, tope);
        cout << "Vis" << endl;
        mostrarArray(vis, tope);
    }

    void prim()
    {
        
        bool *vis = new bool[tope];
        int pos = posOcupada();
        vis[pos] = true;
        int minI, minJ, min;
        for (int k = 0; k < cantVertices - 1; k++)
        {
            minI = minJ = -1;
            min = INF;
            for (int i = 0; i < tope; i++)
            {   
                if (vis[i])
                {
                    for (int j = 0; j < tope; j++)
                    {
                        if (!vis[j] && matAdy[i][j]->existe && matAdy[i][j]->costo < min)
                        {
                            minI = i;
                            minJ = j;
                            min = matAdy[i][j]->costo;
                        }
                    }
                }
            }
            cout << *vertices[minI] << " --> " << *vertices[minJ] << " = " << min << endl;
            vis[minJ] = true;
        }
        delete[] vis;
    }

    bool esConexo(int origen)
    {
        int cantVert = 0;
        int posOrigen = posVertice(origen);
        bool *vis = new bool[tope];
        for (int i = 0; i < tope; vis[i++] = false)
            ;
        Lista<int> *cola = new Lista<int>();
        cola->insertarFin(posOrigen);
        while (!cola->esVacia())
        {
            int pos = cola->obtenerPpio();
            cola->borrarPpio();
            vis[pos] = true;
            cantVert++;
            for (int j = 0; j < tope; j++)
            {
                if (!vis[j] && this->matAdy[pos][j]->existe && !cola->existe(j))
                {
                    cola->insertarFin(j);
                    //vis[j] = true;
                }
            }
        }
        return cantVert == this->cantVertices;
    }

    bool esTriconexo()
    {
        for (int i = 0; i < tope; i++)
        {
            for (int j = i+1; j < tope && j != i; j++)
            {
                if (!esConexo(i, j, this->cantVertices - 2))
                {
                    return false;
                }
            }
        }
        return true;
    }
     void kruskal(){
            Lista<Arista *> * aristas = new Lista<Arista *>();
            for(int i=0; i<tope; i++){
                for(int j=i+1; j<tope; j++){
                    if(matAdy[i][j]->existe){
                        aristas->insertarOrd(matAdy[i][j], fCompArista);
                    }
                }
            }

            Lista<int>** compConexas = new Lista<int>*[tope];
            for(int i=0; i<tope; i++){
                compConexas[i] = new Lista<int>();
                if(vertices[i]){
                    compConexas[i]->insertarPpio(i);
                }
            }

            int posO, posD;
            int cantAristas = 0;
            while(cantAristas < cantVertices-1){
                Arista * arista = aristas->obtenerPpio();
                aristas->borrarPpio();
                for(int i=0; i<tope; i++){
                    if(compConexas[i]->existe(arista->origen)){
                        posO = i;
                    }
                    if(compConexas[i]->existe(arista->destino)){
                        posD = i;
                    }
                }
                if(posO != posD){
                    cantAristas++;
                    cout << *vertices[arista->origen] << " --> " << *vertices[arista->destino] << " = " << arista->costo << endl;
                    Lista<int>* listaO = compConexas[posO];
                    Lista<int>* listaD = compConexas[posD];
                    IteradorLista<int> * it = listaD->obtenerIterador();
                    while(it->hayElemento()){
                        int posV = it->obtenerElemento();
                        listaO->insertarFin(posV);
                        it->avanzar();
                    }
                    listaD->vaciar();
                    delete it;
                }
            }

            delete aristas;
            for(int i=0; i<tope; i++){
                delete compConexas[i];
            }
            delete [] compConexas;
        }
};


void pruebaGrafoConexo()
{
    Grafo *g = new Grafo(4, false);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarArista(1, 2, 10);
    g->insertarArista(2, 3, 40);
    g->insertarArista(3, 1, 40);
    g->insertarArista(1, 4, 40);
    g->insertarArista(4, 3, 60);

    g->BFS(1);
    if (g->esConexo(1))
    {
        cout << "es" << endl;
    }
    else
    {
        cout << "no es" << endl;
    }
}

void pruebaGrafoTriconexo()
{

    Grafo *g = new Grafo(4, false);
    g->insertarVertice(1);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(2);
    g->insertarArista(1, 2, 10);
    g->insertarArista(2, 3, 40);
    g->insertarArista(3, 1, 40);
    g->insertarArista(1, 4, 40);
    g->insertarArista(4, 3, 60);
    //g->insertarArista(4, 2, 60);


    /*
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarArista(1,2,10);
    g->insertarArista(1,3,20);
    g->insertarArista(1,4,30);
    g->insertarArista(2,3,40);
    g->insertarArista(2,4,50);
    g->insertarArista(3,4,60);
    */

    if (g->esTriconexo())
    {
        cout << "ES" << endl;
    }
    if (!g->esTriconexo())
    {
        cout << "NO ES" << endl;
    }
}


void pruebaOrdenTopologico()
{
    Grafo *g = new Grafo(10, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);
    g->insertarVertice(6);
    g->insertarVertice(7);

    g->insertarArista(1, 2, 1);
    g->insertarArista(1, 3, 1);
    g->insertarArista(1, 4, 1);
    g->insertarArista(2, 4, 1);
    g->insertarArista(2, 5, 1);
    g->insertarArista(3, 6, 1);
    g->insertarArista(4, 3, 1);
    g->insertarArista(4, 6, 1);
    g->insertarArista(4, 7, 1);
    g->insertarArista(5, 4, 1);
    g->insertarArista(5, 7, 1);
    g->insertarArista(7, 6, 1);

    g->ordenTopologico();
}

void pruebaBFS()
{
    Grafo *g = new Grafo(5, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);
    g->insertarArista(1, 2, 1);
    g->insertarArista(4, 1, 1);
    g->insertarArista(4, 5, 1);
    g->insertarArista(5, 2, 1);
    g->insertarArista(2, 3, 1);
    g->BFS(1);
}

void pruebaDFS()
{
    Grafo *g = new Grafo(4, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarArista(1, 2, 10);
    g->insertarArista(2, 3, 40);
    g->insertarArista(3, 1, 40);
    g->insertarArista(1, 4, 40);
    g->insertarArista(4, 3, 60);
    g->DFS(1);
}

void pruebaDijkstra()
{
    Grafo *g = new Grafo(7, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);
    g->insertarVertice(6);
    g->insertarVertice(7);

    g->insertarArista(1, 2, 2);
    g->insertarArista(1, 3, 5);
    g->insertarArista(1, 4, 1);
    g->insertarArista(2, 4, 2);
    g->insertarArista(2, 5, 3);
    g->insertarArista(3, 6, 10);
    g->insertarArista(4, 3, 3);
    g->insertarArista(4, 6, 4);
    g->insertarArista(4, 7, 6);
    g->insertarArista(5, 4, 3);
    g->insertarArista(5, 7, 1);
    g->insertarArista(7, 6, 1);

    g->dijkstra(1);
}

void pruebaPrim()
{
    Grafo *g = new Grafo(7, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);
    g->insertarVertice(6);
    g->insertarVertice(7);
    g->insertarArista(1, 2, 2);
    g->insertarArista(1, 3, 4);
    g->insertarArista(1, 4, 1);
    g->insertarArista(2, 4, 3);
    g->insertarArista(2, 5, 10);
    g->insertarArista(3, 4, 2);
    g->insertarArista(3, 6, 5);
    g->insertarArista(4, 5, 7);
    g->insertarArista(4, 6, 8);
    g->insertarArista(4, 7, 4);
    g->insertarArista(5, 7, 6);
    g->insertarArista(6, 7, 1);

    g->prim();
}

int main()
{
    pruebaGrafoTriconexo();
    return 0;
}