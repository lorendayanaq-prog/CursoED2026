#include "pasajero.h"

/* Inicializar la cola */
void inicializarCola(ColaPasajero *cola)
{
    cola->frente = NULL;
    cola->final = NULL;
      cola->totalEmbarcados = 0;
}

/* Verificar si la cola está vacía */
int colaVacia(ColaPasajero *cola)
{
    if (cola->frente == NULL)
    {
        return 1;
    }

    return 0;
}

/* Crear un nuevo pasajero */
NodoPasajero *crearPasajero(int documento, int tipoDocumento)
{
    NodoPasajero *nuevo;

    nuevo = (NodoPasajero *)malloc(sizeof(NodoPasajero));

    if (nuevo == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return NULL;
    }

    nuevo->documento = documento;
    nuevo->tipoDocumento = tipoDocumento;

    strcpy(nuevo->estado, "En espera");

    nuevo->sig = NULL;

    return nuevo;
}

/* Buscar un pasajero en todos los destinos */
NodoPasajero *buscarPasajero(ListaDestino *lista, int documento)
{
    NodoDestino *destino;
    NodoPasajero *aux;

    destino = lista->cab;

    while (destino != NULL)
    {
        aux = destino->cola.frente;

        while (aux != NULL)
        {
            if (aux->documento == documento)
            {
                return aux;
            }

            aux = aux->sig;
        }

        destino = destino->sig;
    }

    return NULL;
}
/* Registrar un pasajero */
void registrarPasajero(ListaDestino *lista)
{
    int codigoDestino;
    int documento;
    int tipoDocumento;

    NodoDestino *destino;
    NodoPasajero *nuevo;

    printf("\nCodigo del destino: ");
    scanf("%d", &codigoDestino);

    destino = buscarDestino(lista, codigoDestino);

    if (destino == NULL)
    {
        printf("\nDestino no encontrado.\n");
        return;
    }

    printf("Documento: ");
    scanf("%d", &documento);

    if (buscarPasajero(lista, documento) != NULL)
    {
        printf("\nEl pasajero ya existe.\n");
        return;
    }

    printf("\nTipo de documento");
    printf("\n1. Cedula");
    printf("\n2. Pasaporte");
    printf("\n3. Tarjeta de Identidad");
    printf("\nSeleccione: ");
    scanf("%d", &tipoDocumento);

    nuevo = crearPasajero(documento, tipoDocumento);

    if (nuevo == NULL)
    {
        return;
    }

    if (colaVacia(&destino->cola))
    {
        destino->cola.frente = nuevo;
        destino->cola.final = nuevo;
    }
    else
    {
        destino->cola.final->sig = nuevo;
        destino->cola.final = nuevo;
    }

    printf("\nPasajero registrado correctamente.\n");
}

/* Mostrar pasajeros de un destino */
void mostrarPasajerosDestino(ListaDestino *lista)
{
    int codigoDestino;

    NodoDestino *destino;
    NodoPasajero *aux;

    printf("\nCodigo del destino: ");
    scanf("%d", &codigoDestino);

    destino = buscarDestino(lista, codigoDestino);

    if (destino == NULL)
    {
        printf("\nDestino no encontrado.\n");
        return;
    }

    if (colaVacia(&destino->cola))
    {
        printf("\nNo hay pasajeros registrados.\n");
        return;
    }

    aux = destino->cola.frente;

    printf("\n====== PASAJEROS ======\n");

    while (aux != NULL)
    {
        printf("\nDocumento: %d", aux->documento);
        printf("\nTipo Documento: %d", aux->tipoDocumento);
        printf("\nEstado: %s", aux->estado);
        printf("\n-----------------------");

        aux = aux->sig;
    }
}

/* Consultar primer pasajero */
void consultarPrimerPasajero(ListaDestino *lista)
{
    int codigoDestino;

    NodoDestino *destino;

    printf("\nCodigo del destino: ");
    scanf("%d", &codigoDestino);

    destino = buscarDestino(lista, codigoDestino);

    if (destino == NULL)
    {
        printf("\nDestino no encontrado.\n");
        return;
    }

    if (colaVacia(&destino->cola))
    {
        printf("\nLa cola esta vacia.\n");
        return;
    }

    printf("\nPrimer pasajero");
    printf("\nDocumento: %d", destino->cola.frente->documento);
    printf("\nEstado: %s", destino->cola.frente->estado);
}

/* Embarcar pasajero */
void embarcarPasajero(ListaDestino *lista)
{
    int codigoDestino;

    NodoDestino *destino;
    NodoPasajero *aux;


    printf("\nCodigo del destino: ");
    scanf("%d",&codigoDestino);



    destino = buscarDestino(lista,codigoDestino);


    if(destino == NULL)
    {
        printf("\nDestino no encontrado\n");
        return;
    }


    if(colaVacia(&destino->cola))
    {
        printf("\nNo hay pasajeros esperando\n");
        return;
    }



    aux = destino->cola.frente;



    destino->cola.frente = aux->sig;



    if(destino->cola.frente == NULL)
    {
        destino->cola.final = NULL;
    }



    destino->cola.totalEmbarcados++;


    printf("\nPasajero embarcado");
    printf("\nDocumento: %d\n",aux->documento);



    free(aux);
}


/* Contar pasajeros */
int contarPasajeros(ColaPasajero *cola)
{
    int contador = 0;

    NodoPasajero *aux = cola->frente;

    while (aux != NULL)
    {
        contador++;
        aux = aux->sig;
    }

    return contador;
}

/* Liberar cola */
void liberarCola(ColaPasajero *cola)
{
    NodoPasajero *aux;

    while (cola->frente != NULL)
    {
        aux = cola->frente;

        cola->frente = cola->frente->sig;

        free(aux);
    }

    cola->final = NULL;
}