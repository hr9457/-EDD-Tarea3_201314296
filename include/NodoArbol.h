#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
#include <conio.h>

using namespace std;

class NodoArbol
{
    private:
        string dato;
        NodoArbol *padre;
        NodoArbol *derecha;
        NodoArbol *izquierda;

    public:
        NodoArbol(string);


};

#endif // NODOARBOL_H
