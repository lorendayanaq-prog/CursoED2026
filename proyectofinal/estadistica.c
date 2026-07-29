#include "estadistica.h"

/* Total de destinos */
int totalDestinos(ListaDestino *lista)
{
    int contador = 0;
    NodoDestino *aux;

    aux = lista->cab;

    while (aux != NULL)
    {
        contador++;
        aux = aux->sig;
    }

    return contador;
}

/* Total de pasajeros */
int totalPasajeros(ListaDestino *lista)
{
    int total = 0;
    NodoDestino *aux;

    aux = lista->cab;

    while (aux != NULL)
    {
        total += contarPasajeros(&aux->cola);
        aux = aux->sig;
    }

    return total;
}

/* Total de viajes */
int totalViajes(NodoViaje *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return 1 +
           totalViajes(raiz->izquierdo) +
           totalViajes(raiz->derecho);
}

/* Mostrar estadísticas */
void mostrarEstadisticas(ListaDestino *lista)
{
    NodoDestino *aux;
    int viajes = 0;

    aux = lista->cab;

    while (aux != NULL)
    {
        viajes += totalViajes(aux->raizViajes);
        aux = aux->sig;
    }

    printf("\n========================================");
    printf("\n      ESTADISTICAS DEL SISTEMA");
    printf("\n========================================");

    printf("\nTotal de destinos  : %d", totalDestinos(lista));
    printf("\nTotal de pasajeros : %d", totalPasajeros(lista));
    printf("\nTotal de viajes    : %d", viajes);

    printf("\n========================================\n");
}