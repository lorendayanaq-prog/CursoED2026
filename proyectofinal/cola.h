#ifndef COLA_H
#define COLA_H

typedef struct NodoPasajero
{
    int documento;
    int tipoDocumento;
    char estado[20];

    struct NodoPasajero *sig;

} NodoPasajero;

typedef struct ColaPasajero
{
    NodoPasajero *frente;
    NodoPasajero *final;

    int totalEmbarcados;

} ColaPasajero;

#endif
