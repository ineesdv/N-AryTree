#include "TElemento.h"

void print (TElemento e){
    printf("%s ", e);
}

void asignar(TElemento* nuevo, TElemento original){
    *nuevo = (char*) malloc( (strlen(original)+1) * sizeof(char)); 
    strcpy(*nuevo,original);
}

int igual(TElemento* a, TElemento* b){
    return (strcmp(*a,*b) == 0);
}

void crear(char* palabra, TElemento* e){
   int longi = 1 + strlen(palabra);
   (*e) = (char*) malloc(longi * sizeof(char));
   strcpy(*e,palabra); 
}


