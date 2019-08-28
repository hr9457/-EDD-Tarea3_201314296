#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
#include <conio.h>

using namespace std;

class NodoArbol
{
    public:
        string dato;
        NodoArbol *derecha;
        NodoArbol *izquierda;

        NodoArbol(string);//constructor
};

#endif // NODOARBOL_H
