#include "viajesRN.h"

/* Crear un nuevo viaje */
NodoViaje *crearViaje(int codigoViaje, char fecha[], int capacidad)
{
    NodoViaje *nuevo;

    nuevo = (NodoViaje *)malloc(sizeof(NodoViaje));

    if (nuevo == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return NULL;
    }

    nuevo->codigoViaje = codigoViaje;

    strcpy(nuevo->fecha, fecha);

    nuevo->capacidad = capacidad;
    nuevo->cuposDisponibles = capacidad;

    nuevo->color = ROJO;

    nuevo->padre = NULL;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;

    return nuevo;
}

/* Rotación a la izquierda */
void rotarIzquierda(NodoViaje **raiz, NodoViaje *x)
{
    NodoViaje *y;

    y = x->derecho;

    x->derecho = y->izquierdo;

    if (y->izquierdo != NULL)
    {
        y->izquierdo->padre = x;
    }

    y->padre = x->padre;

    if (x->padre == NULL)
    {
        *raiz = y;
    }
    else if (x == x->padre->izquierdo)
    {
        x->padre->izquierdo = y;
    }
    else
    {
        x->padre->derecho = y;
    }

    y->izquierdo = x;

    x->padre = y;
}

/* Rotación a la derecha */
void rotarDerecha(NodoViaje **raiz, NodoViaje *y)
{
    NodoViaje *x;

    x = y->izquierdo;

    y->izquierdo = x->derecho;

    if (x->derecho != NULL)
    {
        x->derecho->padre = y;
    }

    x->padre = y->padre;

    if (y->padre == NULL)
    {
        *raiz = x;
    }
    else if (y == y->padre->derecho)
    {
        y->padre->derecho = x;
    }
    else
    {
        y->padre->izquierdo = x;
    }

    x->derecho = y;

    y->padre = x;
}

/* Insertar como Árbol Binario de Búsqueda */
NodoViaje *insertarRN(NodoViaje *raiz, NodoViaje *nuevo)
{
    NodoViaje *padre = NULL;
    NodoViaje *actual = raiz;

    while (actual != NULL)
    {
        padre = actual;

        if (nuevo->codigoViaje < actual->codigoViaje)
        {
            actual = actual->izquierdo;
        }
        else
        {
            actual = actual->derecho;
        }
    }

    nuevo->padre = padre;

    if (padre == NULL)
    {
        raiz = nuevo;
    }
    else if (nuevo->codigoViaje < padre->codigoViaje)
    {
        padre->izquierdo = nuevo;
    }
    else
    {
        padre->derecho = nuevo;
    }

    return raiz;
}
/* Balancear el Árbol Rojo-Negro después de insertar */
void balancearInsercion(NodoViaje **raiz, NodoViaje *nuevo)
{
    NodoViaje *padre;
    NodoViaje *abuelo;
    NodoViaje *tio;

    while ((nuevo != *raiz) &&
           (nuevo->color == ROJO) &&
           (nuevo->padre->color == ROJO))
    {
        padre = nuevo->padre;
        abuelo = padre->padre;

        /* Padre es hijo izquierdo */
        if (padre == abuelo->izquierdo)
        {
            tio = abuelo->derecho;

            /* Caso 1: El tío es rojo */
            if ((tio != NULL) && (tio->color == ROJO))
            {
                abuelo->color = ROJO;
                padre->color = NEGRO;
                tio->color = NEGRO;

                nuevo = abuelo;
            }
            else
            {
                /* Caso 2 */
                if (nuevo == padre->derecho)
                {
                    rotarIzquierda(raiz, padre);

                    nuevo = padre;
                    padre = nuevo->padre;
                }

                /* Caso 3 */
                rotarDerecha(raiz, abuelo);

                padre->color = NEGRO;
                abuelo->color = ROJO;

                nuevo = padre;
            }
        }
        else
        {
            /* Padre es hijo derecho */
            tio = abuelo->izquierdo;

            /* Caso 1 */
            if ((tio != NULL) && (tio->color == ROJO))
            {
                abuelo->color = ROJO;
                padre->color = NEGRO;
                tio->color = NEGRO;

                nuevo = abuelo;
            }
            else
            {
                /* Caso 2 */
                if (nuevo == padre->izquierdo)
                {
                    rotarDerecha(raiz, padre);

                    nuevo = padre;
                    padre = nuevo->padre;
                }

                /* Caso 3 */
                rotarIzquierda(raiz, abuelo);

                padre->color = NEGRO;
                abuelo->color = ROJO;

                nuevo = padre;
            }
        }
    }

    (*raiz)->color = NEGRO;
}
/* Registrar un viaje */
void registrarViaje(ListaDestino *lista)
{
    int codigoDestino;
    int codigoViaje;
    int capacidad;
    char fecha[15];

    NodoDestino *destino;
    NodoViaje *nuevo;

    printf("\nCodigo del destino: ");
    scanf("%d", &codigoDestino);

    destino = buscarDestino(lista, codigoDestino);

    if (destino == NULL)
    {
        printf("\nDestino no encontrado.\n");
        return;
    }

    printf("Codigo del viaje: ");
    scanf("%d", &codigoViaje);

    if (buscarViaje(destino->raizViajes, codigoViaje) != NULL)
    {
        printf("\nEl viaje ya existe.\n");
        return;
    }

    printf("Fecha (dd/mm/aaaa): ");
    scanf(" %14s", fecha);

    printf("Capacidad: ");
    scanf("%d", &capacidad);

    nuevo = crearViaje(codigoViaje, fecha, capacidad);

    if (nuevo == NULL)
    {
        return;
    }

    destino->raizViajes = insertarRN(destino->raizViajes, nuevo);

    balancearInsercion(&destino->raizViajes, nuevo);

    printf("\nViaje registrado correctamente.\n");
}

/* Buscar un viaje */
NodoViaje *buscarViaje(NodoViaje *raiz, int codigo)
{
    while (raiz != NULL)
    {
        if (codigo == raiz->codigoViaje)
        {
            return raiz;
        }

        if (codigo < raiz->codigoViaje)
        {
            raiz = raiz->izquierdo;
        }
        else
        {
            raiz = raiz->derecho;
        }
    }

    return NULL;
}

/* Recorrido Inorden */
void mostrarInorden(NodoViaje *raiz)
{
    if (raiz != NULL)
    {
        mostrarInorden(raiz->izquierdo);

        printf("\nCodigo: %d", raiz->codigoViaje);
        printf("\nFecha: %s", raiz->fecha);
        printf("\nCapacidad: %d", raiz->capacidad);
        printf("\nCupos disponibles: %d", raiz->cuposDisponibles);
        printf("\nColor: %s",
               (raiz->color == ROJO) ? "ROJO" : "NEGRO");
        printf("\n-----------------------------");

        mostrarInorden(raiz->derecho);
    }
}

/* Recorrido Preorden */
void mostrarPreorden(NodoViaje *raiz)
{
    if (raiz != NULL)
    {
        printf("\nCodigo: %d", raiz->codigoViaje);
        printf("\nFecha: %s", raiz->fecha);
        printf("\nCapacidad: %d", raiz->capacidad);
        printf("\nCupos disponibles: %d", raiz->cuposDisponibles);
        printf("\nColor: %s",
               (raiz->color == ROJO) ? "ROJO" : "NEGRO");
        printf("\n-----------------------------");

        mostrarPreorden(raiz->izquierdo);
        mostrarPreorden(raiz->derecho);
    }
}

/* Recorrido Postorden */
void mostrarPostorden(NodoViaje *raiz)
{
    if (raiz != NULL)
    {
        mostrarPostorden(raiz->izquierdo);
        mostrarPostorden(raiz->derecho);

        printf("\nCodigo: %d", raiz->codigoViaje);
        printf("\nFecha: %s", raiz->fecha);
        printf("\nCapacidad: %d", raiz->capacidad);
        printf("\nCupos disponibles: %d", raiz->cuposDisponibles);
        printf("\nColor: %s",
               (raiz->color == ROJO) ? "ROJO" : "NEGRO");
        printf("\n-----------------------------");
    }
}

/* Liberar el árbol */
void liberarArbol(NodoViaje *raiz)
{
    if (raiz != NULL)
    {
        liberarArbol(raiz->izquierdo);
        liberarArbol(raiz->derecho);

        free(raiz);
    }
}