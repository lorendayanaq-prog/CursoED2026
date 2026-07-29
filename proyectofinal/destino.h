#ifndef DESTINO_H
#define DESTINO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaraciones adelantadas */
typedef struct ColaPasajero ColaPasajero;
typedef struct NodoViaje NodoViaje;

/* Nodo de la lista de destinos */
typedef struct NodoDestino
{
    int codigo;
    char nombre[50];
    char empresa[50];

    /* Cola FIFO de pasajeros */
    ColaPasajero cola;

    /* Árbol Rojo-Negro de viajes */
    NodoViaje *raizViajes;

    /* Enlace al siguiente nodo */
    struct NodoDestino *sig;

} NodoDestino;

/* Lista de destinos */
typedef struct
{
    NodoDestino *cab;

} ListaDestino;

/* Prototipos */

void inicializarLista(ListaDestino *lista);

NodoDestino *crearDestino(int codigo, char nombre[], char empresa[]);

void registrarDestino(ListaDestino *lista);

NodoDestino *buscarDestino(ListaDestino *lista, int codigo);

void mostrarDestinos(ListaDestino *lista);

void modificarDestino(ListaDestino *lista);

void liberarDestinos(ListaDestino *lista);

#endif