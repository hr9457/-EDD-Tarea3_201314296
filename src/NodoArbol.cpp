#include "NodoArbol.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

NodoArbol::NodoArbol(string informacion)
{
    dato = informacion;
    padre = NULL;
    derecha = NULL;
    izquierda = NULL;
}
