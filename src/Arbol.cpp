#include "Arbol.h"
#include "NodoArbol.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

Arbol::Arbol(){
    raiz = NULL;
}

//METODO PARA AGREGAR UN NODO AL ARBOL
void Arbol::insertar(string informacion){
    NodoArbol *nuevoNodo = new NodoArbol(informacion);
    if(raiz == NULL){
        raiz = nuevoNodo;
        nuevoNodo->padre=raiz;
    }else{
        NodoArbol *nodoAuxiliar = raiz;
        NodoArbol *padre;
        while(true){
            padre = nodoAuxiliar;
            if(informacion < nodoAuxiliar->dato){
                nodoAuxiliar = nodoAuxiliar->izquierda;
                if(nodoAuxiliar==NULL){
                    padre->izquierda = nuevoNodo;
                    nuevoNodo->padre=padre;
                    return;
                }
            }else{
                nodoAuxiliar = nodoAuxiliar->derecha;
                if(nodoAuxiliar==NULL){
                    padre->derecha = nuevoNodo;
                    nuevoNodo->padre=padre;
                    return;
                }
            }
        }
    }//fin de else
}//fin


void Arbol::impresion(NodoArbol *inicio){
    if (inicio != NULL){
        //archivo<<"nodo"<<inicio->dato<<"[ label = \"<C0>|"<<inicio->dato<<"|<C1>\"]; "<<endl;
        cout<<inicio->dato<<endl;
        archivo<<"nodo"<<inicio->dato<<"[ label = \"<C0>|"<<inicio->dato<<"|<C1>\"]; "<<endl;
        if(inicio->izquierda != NULL){
            NodoArbol *siguiente = inicio->izquierda;
            archivo<<"nodo"<<inicio->dato<<":C0->nodo"<<siguiente->dato<<endl;
            impresion(inicio->izquierda);
        }
        if(inicio->derecha != NULL){
            NodoArbol *siguiente = inicio->derecha;
            archivo<<"nodo"<<inicio->dato<<":C1->nodo"<<siguiente->dato<<endl;
            impresion(inicio->derecha);
        }
    }
}

void Arbol::generarDot(){
    archivo.open("dot.txt",ios::out);
    if(archivo.fail()){
        cout<<"no se puedo abrir el archivo"<<endl;
    }else{
        archivo<<"digraph arbol"<<endl;
        archivo<<"{"<<endl;
        archivo<<"rankdir=TB;"<<endl;
        archivo<<"graph [splines=ortho, nodesep=0.5];"<<endl;
        archivo<<"node [shape = record, style=filled, fillcolor=seashell2,width=0.7,height=0.2];"<<endl;
        impresion(raiz);
        archivo<<"}"<<endl;
        archivo.close();
    }
}

void Arbol::borrarNodo(NodoArbol *nodoEncontrado,string nodoAeliminar){

    //PRIMER CASO DONDE EL NODO ENCONTRADO NO TIENE HIJOS
    if( nodoEncontrado->izquierda==NULL  && nodoEncontrado->derecha==NULL ){
        cout<<"nodo eliminado sin hijos"<<endl;
        nodoEncontrado = nodoEncontrado->padre;//BUSQUEDA DEL PADRE DEL NODO
        cout<<"el padre del nodo encontrado es: "<<nodoEncontrado->dato<<endl;
        //VER SI EL NODO A ELMINIAR ESTA HACIA LA DERECHA O IZQUIERDA
        if( nodoAeliminar < nodoEncontrado->dato ){
            nodoEncontrado->izquierda = NULL;
        }else if( nodoAeliminar >= nodoEncontrado->dato ){
            nodoEncontrado->derecha = NULL;
        }
    //FIN DEL PRIMER CASO DONDE LOS NODOS NO TIENE HIJOS
    }
    //SEGUNDO CASO DONDE LOS NODOS POSEEEN HIJOS
    //NODOS PADRES
    //ELIMINACION HACIA ES ELEMENTO HACIA LA DEECHA Y HACIA LA IZQUIERDA POSIBLE SI TUVIERAN + HIJOS
    else if( nodoEncontrado->derecha!=NULL ){
        cout<<"se econtro un nodo con hijos hacia la derecha"<<endl;
        nodoEncontrado = nodoEncontrado->derecha;
        if(nodoEncontrado->izquierda==NULL){
            cout<<"bajo hacia la derecha que seria :"<<nodoEncontrado->dato<<endl;
            nodoEncontrado = nodoEncontrado->padre;
            cout<<"regreso al padre que es: "<<nodoEncontrado->dato<<endl;
            NodoArbol *intercambio = nodoEncontrado->derecha;
            nodoEncontrado->dato = intercambio->dato;
            nodoEncontrado->derecha = NULL;
        }else{
            cout<<"el nodo hacia la derecha es solo hijo"<<endl;
        }
    }
}//FIN DEL METODO PARA BORRAR UN NODO EN UN ARBOL

void Arbol::buscarNodo(NodoArbol *inicio,string nodoAeliminar){
    if( nodoAeliminar == inicio->dato ){
        cout<<"nodo encontrado"<<endl;
        borrarNodo(inicio,nodoAeliminar);
    }else if( nodoAeliminar<inicio->dato && inicio->izquierda!=NULL ){
        inicio = inicio->izquierda;
        buscarNodo(inicio,nodoAeliminar);
    }else if( nodoAeliminar>=inicio->dato && inicio->derecha!=NULL ){
        inicio = inicio->derecha;
        buscarNodo(inicio,nodoAeliminar);
    }else{
        cout<<"el nodo que estas buscando no exite en el arbol"<<endl;
    }
}

void Arbol::eliminarNodo(string nodoAeliminar){
    //NodoArbol *nodoAuxiliar = raiz;
    if(raiz==NULL){
        cout<<"el arbol se encuentra vacio"<<endl;
    }else{
        cout<<"buscando nodo en el arbol"<<endl;
        buscarNodo(raiz,nodoAeliminar);
    }
}

