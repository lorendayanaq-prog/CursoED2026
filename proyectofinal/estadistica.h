#ifndef ESTADISTICA_H
#define ESTADISTICA_H


#include <stdio.h>
#include <stdlib.h>

#include "destino.h"
#include "pasajero.h"
#include "viajesRN.h"



int totalDestinos(ListaDestino *lista);


int totalPasajeros(ListaDestino *lista);


int totalEmbarcados(ListaDestino *lista);


float promedioPasajerosEspera(ListaDestino *lista);


float promedioEmbarcadosViaje(ListaDestino *lista);


NodoDestino *destinoMayorEspera(ListaDestino *lista);


NodoDestino *destinoMenorEspera(ListaDestino *lista);


void mostrarEstadisticas(ListaDestino *lista);



#endif