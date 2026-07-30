#ifndef PASAJERO_H
#define PASAJERO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"
#include "cola.h"



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