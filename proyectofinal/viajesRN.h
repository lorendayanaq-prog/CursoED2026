#ifndef VIAJESRN_H
#define VIAJERSN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"

/* Colores del Árbol Rojo-Negro */
#define ROJO 1
#define NEGRO 0

/* Nodo del Árbol Rojo-Negro */
typedef struct NodoViaje
{
    int codigoViaje;
    char fecha[15];

    int capacidad;
    int cuposDisponibles;

    int color;

    struct NodoViaje *padre;
    struct NodoViaje *izquierdo;
    struct NodoViaje *derecho;

} NodoViaje;

/* Prototipos */

NodoViaje *crearViaje(int codigoViaje, char fecha[], int capacidad);

NodoViaje *buscarViaje(NodoViaje *raiz, int codigo);

NodoViaje *insertarRN(NodoViaje *raiz, NodoViaje *nuevo);

void rotarIzquierda(NodoViaje **raiz, NodoViaje *x);

void rotarDerecha(NodoViaje **raiz, NodoViaje *y);

void balancearInsercion(NodoViaje **raiz, NodoViaje *nuevo);

void registrarViaje(ListaDestino *lista);

void mostrarInorden(NodoViaje *raiz);

void mostrarPreorden(NodoViaje *raiz);

void mostrarPostorden(NodoViaje *raiz);

void liberarArbol(NodoViaje *raiz);

#endif