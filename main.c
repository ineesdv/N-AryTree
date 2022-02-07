#include "TArbolNario.h"

int main(){
    TElemento e_alfonso, e_ana, e_simon, e_miguel;
    TElemento e_jeremias, e_alberto, e_irene, e_gema, e_angel, e_luis, e_felipe, e_jesus, e_maria, e_lucia, e_andres, e_christian, e_daniel;
    TElemento e_susana, e_pedro, e_patricia, e_joel, e_iker;
    TElemento e_laura, e_esther, e_juan, e_roberto, e_paloma, e_blanca, e_marcos, e_cesar, e_silvia, e_teresa, e_guadalupe, e_emilio;

    crear("Alfonso", &e_alfonso);
    crear("Ana", &e_ana);
    crear("Simon", &e_simon);
    crear("Miguel", &e_miguel);

    crear("Jeremias", &e_jeremias);
    crear("Alberto", &e_alberto);
    crear("Irene", &e_irene);
    crear("Gema", &e_gema);
    crear("Angel", &e_angel);
    crear("Luis", &e_luis);
    crear("Felipe", &e_felipe);
    crear("Jesus", &e_jesus);
    crear("Maria", &e_maria);
    crear("Lucia", &e_lucia);
    crear("Andres", &e_andres);
    crear("Christian", &e_christian);
    crear("Daniel", &e_daniel);

    crear("Susana", &e_susana);
    crear("Pedro", &e_pedro);
    crear("Patricia", &e_patricia);
    crear("Joel", &e_joel);
    crear("Iker", &e_iker);

    crear("Laura", &e_laura);
    crear("Esther", &e_esther);
    crear("Juan", &e_juan);
    crear("Roberto", &e_roberto);
    crear("Paloma", &e_paloma);
    crear("Blanca", &e_blanca);
    crear("Marcos", &e_marcos);
    crear("Cesar", &e_cesar);
    crear("Silvia", &e_silvia);
    crear("Teresa", &e_teresa);
    crear("Guadalupe", &e_guadalupe);
    crear("Emilio", &e_emilio);


    // ---- ÁRBOL IMAGEN ----

    TArbolnario FAMILIA;
    crearArbolVacio(&FAMILIA);

    //nivel 1
    anadirRaiz(&FAMILIA, e_alfonso);

    //nivel 2
    anadirHijo(&FAMILIA, e_miguel, e_alfonso);
    anadirHijo(&FAMILIA, e_jeremias, e_alfonso);
    anadirHijo(&FAMILIA, e_susana, e_alfonso);
    anadirHijo(&FAMILIA, e_laura, e_alfonso);

    //nivel 3
    anadirHijo(&FAMILIA, e_simon, e_miguel);
    anadirHijo(&FAMILIA, e_alberto, e_jeremias);
    anadirHijo(&FAMILIA, e_jesus, e_jeremias);
    anadirHijo(&FAMILIA, e_maria, e_jeremias);
    anadirHijo(&FAMILIA, e_pedro, e_susana);
    anadirHijo(&FAMILIA, e_iker, e_susana);
    anadirHijo(&FAMILIA, e_esther, e_laura);
    anadirHijo(&FAMILIA, e_guadalupe, e_laura);
    anadirHijo(&FAMILIA, e_emilio, e_laura);

    //nivel 4
    anadirHijo(&FAMILIA, e_ana, e_simon);
    anadirHijo(&FAMILIA, e_irene, e_alberto);
    anadirHijo(&FAMILIA, e_felipe, e_alberto);
    anadirHijo(&FAMILIA, e_lucia, e_maria);
    anadirHijo(&FAMILIA, e_andres, e_maria);
    anadirHijo(&FAMILIA, e_patricia, e_pedro);
    anadirHijo(&FAMILIA, e_juan, e_esther);
    //anadirHijo(&FAMILIA, e_roberto, e_esther);
    anadirHermano(&FAMILIA, e_juan, e_roberto);
    //anadirHijo(&FAMILIA, e_cesar, e_esther);
    anadirHermano(&FAMILIA, e_roberto, e_cesar);
    //anadirHijo(&FAMILIA, e_silvia, e_esther);
    anadirHermano(&FAMILIA, e_juan, e_silvia);


    //nivel 5
    anadirHijo(&FAMILIA, e_gema, e_irene);
    anadirHijo(&FAMILIA, e_angel, e_irene);
    anadirHijo(&FAMILIA, e_luis, e_irene);
    anadirHijo(&FAMILIA, e_christian, e_andres);
    anadirHijo(&FAMILIA, e_daniel, e_andres);
    anadirHijo(&FAMILIA, e_joel, e_patricia);
    anadirHijo(&FAMILIA, e_paloma, e_roberto);
    //anadirHijo(&FAMILIA, e_blanca, e_roberto);
    anadirHermano(&FAMILIA, e_paloma, e_blanca);
    //anadirHijo(&FAMILIA, e_marcos, e_roberto);
    anadirHermano(&FAMILIA, e_blanca, e_marcos);
    anadirHijo(&FAMILIA, e_teresa, e_silvia);




    //   ------ FUNCIONES -------

    printf("Es arbol vacio? : %d \n", esArbolVacio(FAMILIA));
    printf("Numero de nodos: %d \n", numeroNodos(FAMILIA)); //tiene 34
    printf("Numero de hojas: %d \n", numeroHojas(FAMILIA)); //tiene 19
    printf("Altura: %d \n", altura(FAMILIA)); // altura 5


    // Parent
    TElemento padreAux;
    printf("\nEl padre de Simon es: ");
    parent(FAMILIA, e_simon, &padreAux);
    print(padreAux);

    printf("\nEl padre de Marcos es: ");
    parent(FAMILIA, e_marcos, &padreAux);
    print(padreAux);

    printf("\nEl padre de Alfonso es: ");
    parent(FAMILIA, e_alfonso, &padreAux);
    print(padreAux);

    
    // Lista hijos

    TLinkedList LHijos, LHermanos, LAntepasados;

    crearVacia(&LHijos);
    printf("\n\nHijos de Roberto: ");
    listaHijos(FAMILIA, e_roberto, &LHijos);
    mostrar(LHijos);

    destruir(&LHijos);
    printf("Hijos de Luis: ");
    listaHijos(FAMILIA, e_luis, &LHijos);
    mostrar(LHijos);

    destruir(&LHijos);
    printf("Hijos de Esther: ");
    listaHijos(FAMILIA, e_esther, &LHijos);
    mostrar(LHijos);


    // Lista hermanos
    crearVacia(&LHermanos);
    printf("\nHermanos de Luis: ");
    listaHermanos(FAMILIA, e_luis, &LHermanos);
    mostrar(LHermanos);

    destruir(&LHermanos);
    printf("Hermanos de Patricia: ");
    listaHermanos(FAMILIA, e_patricia, &LHermanos);
    mostrar(LHermanos);

    destruir(&LHermanos);
    printf("Hermanos de Juan: ");
    listaHermanos(FAMILIA, e_juan, &LHermanos);
    mostrar(LHermanos);


    // Lista antepasados
    crearVacia(&LAntepasados);
    printf("\nAntepasados de Maria: ");
    listaAntepasados(FAMILIA, e_maria, &LAntepasados);
    mostrar(LAntepasados);

    destruir(&LAntepasados);
    printf("Antepasados de Roberto: ");
    listaAntepasados(FAMILIA, e_roberto, &LAntepasados);
    mostrar(LAntepasados);

    destruir(&LAntepasados);
    printf("Antepasados de Alfonso: ");
    listaAntepasados(FAMILIA, e_alfonso, &LAntepasados);
    mostrar(LAntepasados);


    // Recorrido
    TLinkedList LRecorrido;
    crearVacia(&LRecorrido);
    printf("\nRecorrido: ");
    recorrido(FAMILIA, &LRecorrido);
    mostrar(LRecorrido);


    // Borrar y copiar arboles
    TArbolnario FAMILIA2;
    crearArbolVacio(&FAMILIA2);
    copiarArbol(FAMILIA, &FAMILIA2);

    borrarArbol(&FAMILIA);
    
    printf("\nEs arbol vacio el borrado? : %d \n", esArbolVacio(FAMILIA));
    printf("Es arbol vacio el copiado? : %d \n", esArbolVacio(FAMILIA2));

    destruir(&LHermanos);
    printf("Arbol copiado - Hermanos de Juan: ");
    listaHermanos(FAMILIA2, e_juan, &LHermanos);
    mostrar(LHermanos);

    printf("Arbol copiado - Numero de nodos: %d \n", numeroNodos(FAMILIA2)); //tiene 34
    printf("Arbol copiado - Altura: %d \n", altura(FAMILIA2)); 

    
    //Borrar Nodo
    TArbolnario FAMILIA3;
    crearArbolVacio(&FAMILIA3);
    copiarArbol(FAMILIA2, &FAMILIA3);

    borrarNodo(&FAMILIA2, e_alfonso);
    destruir(&LRecorrido);
    printf("\nBorramos a Alfonso - Nuevo Recorrido: ");
    recorrido(FAMILIA2, &LRecorrido);
    mostrar(LRecorrido);
    printf("Numero de nodos tras borrar a Alfonso: %d \n", numeroNodos(FAMILIA2));

    borrarNodo(&FAMILIA3, e_blanca);
    destruir(&LRecorrido);
    printf("\nBorramos a Blanca - Nuevo Recorrido: ");
    recorrido(FAMILIA3, &LRecorrido);
    mostrar(LRecorrido);
    

    return 0;
}