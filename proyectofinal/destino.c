#include "destino.h"
#include "pasajero.h"

/* Inicializar lista */
void inicializarLista(ListaDestino *lista)
{
    lista->cab = NULL;
}

/* Crear destino */
NodoDestino *crearDestino(int codigo, char nombre[], char empresa[])
{
    NodoDestino *nuevo;

    nuevo = (NodoDestino *)malloc(sizeof(NodoDestino));

    if (nuevo == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return NULL;
    }

    nuevo->codigo = codigo;

    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->empresa, empresa);

    inicializarCola(&nuevo->cola);

    nuevo->raizViajes = NULL;

    nuevo->sig = NULL;

    return nuevo;
}

/* Buscar destino */
NodoDestino *buscarDestino(ListaDestino *lista, int codigo)
{
    NodoDestino *aux;

    aux = lista->cab;

    while (aux != NULL)
    {
        if (aux->codigo == codigo)
        {
            return aux;
        }

        aux = aux->sig;
    }

    return NULL;
}

/* Registrar destino */
void registrarDestino(ListaDestino *lista)
{
    NodoDestino *nuevo;
    NodoDestino *aux;

    int codigo;
    char nombre[50];
    char empresa[50];

    printf("\n========== REGISTRAR DESTINO ==========\n");

    printf("Codigo: ");
    scanf("%d", &codigo);

    if (buscarDestino(lista, codigo) != NULL)
    {
        printf("\nEl codigo ya existe.\n");
        return;
    }

    printf("Nombre del destino: ");
    scanf(" %[^\n]", nombre);

    printf("Empresa: ");
    scanf(" %[^\n]", empresa);

    nuevo = crearDestino(codigo, nombre, empresa);

    if (nuevo == NULL)
    {
        return;
    }

    if (lista->cab == NULL)
    {
        lista->cab = nuevo;
    }
    else
    {
        aux = lista->cab;

        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }

    printf("\nDestino registrado correctamente.\n");
}

/* Mostrar destinos */
void mostrarDestinos(ListaDestino *lista)
{
    NodoDestino *aux;

    aux = lista->cab;

    if (aux == NULL)
    {
        printf("\nNo hay destinos registrados.\n");
        return;
    }

    printf("\n========== DESTINOS ==========\n");

    while (aux != NULL)
    {
        printf("\nCodigo   : %d", aux->codigo);
        printf("\nDestino  : %s", aux->nombre);
        printf("\nEmpresa  : %s", aux->empresa);
        printf("\n------------------------------");

        aux = aux->sig;
    }
}

/* Modificar destino */
void modificarDestino(ListaDestino *lista)
{
    int codigo;

    NodoDestino *destino;

    printf("\nCodigo del destino: ");
    scanf("%d", &codigo);

    destino = buscarDestino(lista, codigo);

    if (destino == NULL)
    {
        printf("\nDestino no encontrado.\n");
        return;
    }

    printf("Nuevo nombre: ");
    scanf(" %[^\n]", destino->nombre);

    printf("Nueva empresa: ");
    scanf(" %[^\n]", destino->empresa);

    printf("\nDestino modificado correctamente.\n");
}

/* Liberar lista */
void liberarDestinos(ListaDestino *lista)
{
    NodoDestino *aux;

    while (lista->cab != NULL)
    {
        aux = lista->cab;

        lista->cab = lista->cab->sig;

        liberarCola(&aux->cola);

        free(aux);
    }
}