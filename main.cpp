#include <iostream>
#include <conio.h>
#include "Arbol.h"

using namespace std;

int main()
{
    Arbol tree;
    tree.insertar("luigui");
    tree.insertar("hammer");
    tree.insertar("mario");
    tree.insertar("peach");
    tree.insertar("pow");
    tree.insertar("fermin");
    //tree.impresion(tree.raiz);
    tree.generarDot();
    tree.eliminarNodo("hector");
    return 0;
}
