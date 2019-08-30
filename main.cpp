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
    //tree.generarDot();
    //tree.generarImagenDot();
    //tree.impresion(tree.raiz);

    cout<<"---------------------"<<endl;
    tree.eliminarNodo("peach");
    //tree.generarDot();
    //tree.generarImagenDot();
    cout<<"---------------------"<<endl;

    cout<<"---------------------"<<endl;
    tree.insertar("shy_guy");
    tree.insertar("edd");
    //tree.generarDot();
    //tree.generarImagenDot();
    cout<<"---------------------"<<endl;

    cout<<"---------------------"<<endl;
    tree.eliminarNodo("pow");
    //tree.generarDot();
    //tree.generarImagenDot();
    cout<<"---------------------"<<endl;

    cout<<"---------------------"<<endl;
    tree.insertar("Boo");
    tree.insertar("Kamek");
    tree.insertar("star");
    tree.insertar("whomp");
    //tree.generarDot();
    //tree.generarImagenDot();
    cout<<"---------------------"<<endl;

    cout<<"---------------------"<<endl;
    tree.eliminarNodo("shy_guy");
    //tree.generarDot();
    //tree.generarImagenDot();
    cout<<"---------------------"<<endl;


    cout<<"---------------------"<<endl;
    tree.eliminarNodo("mario");
    tree.generarDot();
    tree.generarImagenDot();
    cout<<"---------------------"<<endl;

    return 0;
}
