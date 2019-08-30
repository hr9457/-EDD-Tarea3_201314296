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
        void eliminarNodo(string);
        void buscarNodo(NodoArbol*,string);
        void borrarNodo(NodoArbol*,string);
        void generarImagenDot();
};

#endif // ARBOL_H
