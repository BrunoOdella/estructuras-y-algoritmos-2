#ifndef AVL_H
#define AVL_H

struct RepresentacionAVL;
typedef RepresentacionAVL * AVL;

//PRE: -
//POS: Crea un AVL vacío y lo devuelve
AVL crearAVL();

//PRE: -
//POS: Agrega el elemento x al AVL
void agregar(AVL a, int x);

#endif