#ifndef PASAJERO_H
#define PASAJERO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"


/* Nodo de pasajero */
typedef struct NodoPasajero
{
    int documento;

    int tipoDocumento;

    char estado[20];

    struct NodoPasajero *sig;

}NodoPasajero;


/* Cola FIFO de pasajeros */

typedef struct ColaPasajero
{
    NodoPasajero *frente;

    NodoPasajero *final;

    int totalEmbarcados;

}ColaPasajero;



/* Prototipos */

void inicializarCola(ColaPasajero *cola);

int colaVacia(ColaPasajero *cola);

NodoPasajero *crearPasajero(int documento, int tipoDocumento);


NodoPasajero *buscarPasajero(ListaDestino *lista, int documento);


void registrarPasajero(ListaDestino *lista);


void mostrarPasajerosDestino(ListaDestino *lista);


void consultarPrimerPasajero(ListaDestino *lista);


void embarcarPasajero(ListaDestino *lista);


int contarPasajeros(ColaPasajero *cola);


int contarEmbarcados(ColaPasajero *cola);


void consultarPasajero(ListaDestino *lista);


void liberarCola(ColaPasajero *cola);


#endif