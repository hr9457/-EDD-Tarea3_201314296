#ifndef ARBOL_H
#define ARBOL_H
#include "NodoArbol.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;

class Arbol
{
    private:


    public:
        NodoArbol *raiz;
        ofstream archivo;
        int contadorNodos=0;
        Arbol();//constructor
        void insertar(string);
        void impresion(NodoArbol*);
        void generarDot();
};

#endif // ARBOL_H
