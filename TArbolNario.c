#include "TArbolNario.h"

void crearArbolVacio(TArbolnario* a){
    *a = NULL;
}


void anadirRaiz(TArbolnario* a, TElemento raiz){
    TNodoArbol* nuevo = (TNodoArbol*) malloc(sizeof(TNodoArbol));
    asignar(&(nuevo->info), raiz);
    nuevo->padre = NULL;
    nuevo->hermano = NULL;
    nuevo->hijo = NULL;
    *a = nuevo;

}

void anadirHijo(TArbolnario* a, TElemento hijo, TElemento padre){
    if(!esArbolVacio(*a)){ 
        int encontrado = 0;
        encontrado = igual(&padre, &((*a)->info));

        if(encontrado){
            TNodoArbol* nuevoHijo = (TNodoArbol*) malloc(sizeof(TNodoArbol));
            anadirRaiz(&nuevoHijo, hijo); 

            if((*a)->hijo == NULL){
                (*a)->hijo = nuevoHijo;
            }else{
                 //procedo a insertar en  hijos
                TNodoArbol* aux = (*a)->hijo;
                while(aux->hermano != NULL){  //busco ult posicion 
                    aux = aux->hermano;
                }
                aux->hermano = nuevoHijo;
            }
            nuevoHijo->padre = *a;

        }else{
            anadirHijo(&(*a)->hermano, hijo, padre);
            anadirHijo(&(*a)->hijo, hijo, padre);
        }
    }
}

void anadirHermano(TArbolnario* a, TElemento hermano, TElemento NuevoHermano){
    if(!esArbolVacio(*a)){ 
        int encontrado = 0;
        encontrado = igual(&hermano, &((*a)->info));
        
        if(encontrado){
            TNodoArbol* aux;
            aux = *a;

            while(aux->hermano != NULL){  //busco ult posicion 
                aux = aux->hermano;
            }

            TNodoArbol* nuevoHer = (TNodoArbol*) malloc(sizeof(TNodoArbol));
            anadirRaiz(&nuevoHer, NuevoHermano);
            aux->hermano = nuevoHer;
            nuevoHer->padre = aux->padre;

        }else{
            anadirHermano(&(*a)->hermano, hermano, NuevoHermano);
            anadirHermano(&(*a)->hijo, hermano, NuevoHermano);
        }
    }
}

void borrarArbol(TArbolnario* a){
    if(!esArbolVacio(*a)){
        borrarArbol(&(*a)->hermano);
        borrarArbol(&(*a)->hijo);
        free(*a);
        *a = NULL;
    }
}

void hacerCopia(TArbolnario original, TArbolnario* copia){ //funcion auxiliar
    if (esArbolVacio(original)){
        crearArbolVacio(copia);
    }else{
        TArbolnario abajo, derecha;
        copiarArbol((original)->hermano,&derecha);
        copiarArbol((original)->hijo,&abajo);
        TNodoArbol* aux = (TNodoArbol*) malloc(sizeof(TNodoArbol));
        asignar(&aux->info, original->info);
        aux->hermano = derecha;
        aux->hijo = abajo;
        *copia = aux;
    }
}

void asignarPadres(TArbolnario* a){  //funcion auxiliar
    if(!esArbolVacio(*a)){
        TNodoArbol* aux = (*a)->hijo;
        while(aux != NULL){
            aux->padre = *a;
            asignarPadres(&aux);
            aux = aux->hermano;
        }
    }
}

void copiarArbol(TArbolnario original, TArbolnario* copia){
    hacerCopia(original, copia);
    asignarPadres(copia);
}

int esArbolVacio(TArbolnario a){
    return ( a == NULL );
}

int numeroNodos(TArbolnario a){
    if(!esArbolVacio(a)){ 
        return 1 + numeroNodos(a->hermano) + numeroNodos(a->hijo);
    }else{
        return 0;
    }

}

int numeroHojas(TArbolnario a){
    if(!esArbolVacio(a)){ 
        if(a->hijo == NULL){ // hoja 
            return 1 + numeroHojas(a->hermano);  
        }else{
            return numeroHojas(a->hermano) + numeroHojas(a->hijo);
        }
    }else{
        return 0;
    }
}


int altura(TArbolnario a){ 
    if(!esArbolVacio(a)){
        TNodoArbol* aux = a;
        int contador = 0;
        int max = 0;
        while(aux != NULL){
            contador = altura(aux->hijo);
            if(contador > max){
                max = contador;
            }
            aux = aux->hermano;
        }
        return 1 + max;
    }else{
        return 0;
    }
}

void parent(TArbolnario a, TElemento e, TElemento* padre){
      if(!esArbolVacio(a)){ 
        int encontrado = 0;
        encontrado = igual(&e, &(a->info));
        if(encontrado){
            if(a->padre == NULL){
                char* aux= "No tiene padre";
                TElemento ElementoAux;
                crear(aux, &ElementoAux);
                asignar(padre, ElementoAux);
            }else{
                asignar(padre, (a->padre)->info);
            }
        }else{
            parent(a->hermano, e, padre),
            parent(a->hijo, e, padre);
        }
    }
}

void listaHijos(TArbolnario a, TElemento padre, TLinkedList* hijos){
    if(!esArbolVacio(a)){
        int encontrado = 0;
        encontrado = igual(&(a->info), &padre);
        if(encontrado){
            crearVacia(hijos);
            TNodoArbol* aux = a->hijo;
            while(aux != NULL){
                insertarFinal(aux->info, hijos);
                aux = aux->hermano;
            }

        }else{
            listaHijos(a->hermano, padre, hijos);
            listaHijos(a->hijo, padre, hijos);
        }
    }

}

void listaHermanos(TArbolnario a, TElemento hermano, TLinkedList* hermanos){
    if(!esArbolVacio(a)){
        int encontrado = 0;
        encontrado = igual(&(a->info), &hermano);
        if(encontrado){
            crearVacia(hermanos);
            TNodoArbol* aux = a->padre;
            aux = aux->hijo; //me posiciono en el primer hermano
            while(aux != NULL){
                if(!igual(&(aux->info), &hermano)){
                    insertarFinal(aux->info, hermanos);
                }
                aux = aux->hermano;
            }
    
        }else{
            listaHermanos(a->hermano, hermano, hermanos);
            listaHermanos(a->hijo, hermano, hermanos);
        }
    }
}

void listaAntepasados(TArbolnario a, TElemento p, TLinkedList* antecesores){
    if(!esArbolVacio(a)){
        int encontrado = 0;
        encontrado = igual(&(a->info), &p);
        if(encontrado){
            crearVacia(antecesores);
            TNodoArbol* aux = a->padre;
            while(aux != NULL){
                insertarFinal(aux->info, antecesores);
                aux = aux->padre;
            }

        }else{
            listaAntepasados(a->hermano, p, antecesores);
            listaAntepasados(a->hijo, p, antecesores);
        }
    }
}

// void listaAntepasados(TArbolnario a, TElemento p, TLinkedList* antecesores){   MAL: incluye a los tíos, hermanos de abuelos, etc
//     if(!esArbolVacio(a)){
//         int encontrado = 0;
//         encontrado = igual(&(a->info), &p);
//         if(encontrado){
//             TNodoArbol* aux = a->padre;
//             TLinkedList listaAux;
//             while(aux->padre != NULL){
//                 aux = aux->padre;
//                 crearVacia(&listaAux);
//                 listaHijos(aux, aux->info, &listaAux);
//                 concatenar(antecesores, listaAux);
//                // mostrar(listaAux);
//             }
//             //falta la altura 1:
//                 while(aux != NULL){
//                     insertarFinal(aux->info, antecesores);
//                     aux = aux->hermano;
//                 }
//         }else{
//             listaAntepasados(a->hermano, p, antecesores);
//             listaAntepasados(a->hijo, p, antecesores);
//         }
//     }
// }

void ListaNivel(TArbolnario a, int nivel, TLinkedList* recorrido){   //funcion auxiliar
    if(!esArbolVacio(a)){
        if(nivel == 1){
            insertarFinal(a->info, recorrido);
        }
        else{
            TNodoArbol* aux = a->hijo;
            while(aux != NULL){
                ListaNivel(aux, nivel-1, recorrido);
                aux = aux->hermano;
            }
            
        }
    }
}

void recorrido(TArbolnario a, TLinkedList* camino){
    if(!esArbolVacio(a)){
        crearVacia(camino);
        int numNiveles = altura(a);

        for (int i = 1; i <= numNiveles; i++)
        {
            ListaNivel(a, i, camino);
        }

    }
}

// void recorrido(TArbolnario a, TLinkedList* camino){  MAL: recorrido de izq a dcha, y de arriba a abajo
//     if(!esArbolVacio(a)){
//         TNodoArbol* aux = a;
//         while(aux != NULL){
//             insertarFinal(aux->info, camino);
//             aux = aux->hermano;
//         }
//         
//         TNodoArbol* aux = a->hijo;
//          while(aux != NULL){
//             recorrido(aux->hijo, camino);
//             aux = aux->hermano;
//         }
//     }
// }



void eliminarNodos(TArbolnario* a){   //funcion auxiliar
    if(!esArbolVacio(*a)){
        if(((*a)->hijo == NULL) && ((*a)->hermano == NULL)){ //sin descendencia ni hermanos
            free(*a);
            crearArbolVacio(a);

        }else if(((*a)->hijo == NULL) && ((*a)->hermano != NULL)){ //sin descendencia pero con hermanos
            TNodoArbol* padre = (*a)->padre;
            if( igual(&(padre->hijo->info),&(*a)->info) ){//primer hijo
                padre->hijo = (*a)->hermano;
            }else{//hijo intermedio
                TNodoArbol* ant = padre->hijo;
                while( !igual(&ant->hermano->info, &(*a)->info) ){
                    ant = ant->hermano;
                }
                TNodoArbol* sig = (*a)->hermano;
                ant->hermano = sig;
            }
            free(*a);

        }else if(((*a)->hijo != NULL) && ((*a)->hermano == NULL)){ // con descendencia pero sin hermanos
            asignar(&(*a)->info, (*a)->hijo->info);
            eliminarNodos(&(*a)->hijo);

        }else{ //descendencia y hermanos
            asignar(&(*a)->info, (*a)->hijo->info);
            eliminarNodos(&(*a)->hijo);
        }
    }
}

void borrarNodo(TArbolnario* a, TElemento e){
    if(!esArbolVacio(*a)){
        int encontrado = 0;
        encontrado = igual(&(*a)->info, &e);
        if(encontrado){
            eliminarNodos(a);
        }else{
            borrarNodo(&(*a)->hermano, e);
            borrarNodo(&(*a)->hijo, e);
        }
    }
}
