#include "TElemento.h"
#include "simplelinkedlist.h"

typedef struct NodoArbol{
    struct NodoArbol* padre;
    struct NodoArbol* hijo;
    struct NodoArbol* hermano;
    TElemento info;
}TNodoArbol;

typedef TNodoArbol* TArbolnario;


void crearArbolVacio(TArbolnario* a);
void anadirRaiz(TArbolnario* a, TElemento raiz);
void anadirHijo(TArbolnario* a, TElemento hijo, TElemento padre);
void anadirHermano(TArbolnario* a, TElemento hermano, TElemento NuevoHermano);
void borrarArbol(TArbolnario* a);
void copiarArbol(TArbolnario original, TArbolnario* copia);
int esArbolVacio(TArbolnario a);
int numeroNodos(TArbolnario a);
int numeroHojas(TArbolnario a);
int altura(TArbolnario a);
void parent(TArbolnario a, TElemento e, TElemento* padre);
void listaHijos(TArbolnario a, TElemento padre, TLinkedList* hijos);
void listaHermanos(TArbolnario a, TElemento hermano, TLinkedList* hermanos);
void listaAntepasados(TArbolnario a, TElemento p, TLinkedList* antecesores);
void recorrido(TArbolnario a, TLinkedList* camino);
void borrarNodo(TArbolnario* a, TElemento e);
