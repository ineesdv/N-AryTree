#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* TElemento;

void print (TElemento e);

void asignar(TElemento* nuevo, TElemento original);

int igual(TElemento* a, TElemento* b);

void crear(char* palabra, TElemento* e);