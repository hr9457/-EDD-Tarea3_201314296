#include "NodoArbol.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

NodoArbol::NodoArbol(string informacion)
{
    dato = informacion;
    derecha = NULL;
    izquierda = NULL;
}
