#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NodoCola {
    char nombre[50];
    char ciudad[50];
    char tema[100];
    struct NodoCola *sig;
} NodoCola;

typedef struct {
    NodoCola *frente;
    NodoCola *final;
} Cola;

typedef struct NodoPila {
    char nombre[50];
    char ciudad[50];
    char tema[100];
    struct NodoPila *sig;
} NodoPila;

typedef struct {
    NodoPila *tope;
} Pila;

void inicializarCola(Cola *c) {
    c->frente = NULL;
    c->final = NULL;
}

int colaVacia(Cola *c) {
    return c->frente == NULL;
}

void encolar(Cola *c) {
    NodoCola *nuevo = (NodoCola *)malloc(sizeof(NodoCola));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    printf("\nNombre: ");
    getchar();
    fgets(nuevo->nombre, 50, stdin);
    nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';

    printf("Ciudad: ");
    fgets(nuevo->ciudad, 50, stdin);
    nuevo->ciudad[strcspn(nuevo->ciudad, "\n")] = '\0';

    printf("Tema de participacion: ");
    fgets(nuevo->tema, 100, stdin);
    nuevo->tema[strcspn(nuevo->tema, "\n")] = '\0';

    nuevo->sig = NULL;

    if (colaVacia(c)) {
        c->frente = nuevo;
        c->final = nuevo;
    } else {
        c->final->sig = nuevo;
        c->final = nuevo;
    }

    printf("\nOyente registrado correctamente.\n");
}

void mostrarCola(Cola *c) {

    if (colaVacia(c)) {
        printf("\nLa cola esta vacia.\n");
        return;
    }

    NodoCola *aux = c->frente;

    printf("\nCOLA DE LLAMADAS\n");

    while (aux != NULL) {
        printf("\nNombre: %s", aux->nombre);
        printf("\nCiudad: %s", aux->ciudad);
        printf("\nTema: %s\n", aux->tema);

        aux = aux->sig;
    }
}

void liberarCola(Cola *c) {

    NodoCola *aux;

    while (c->frente != NULL) {
        aux = c->frente;
        c->frente = c->frente->sig;
        free(aux);
    }

    c->final = NULL;
}

void inicializarPila(Pila *p) {
    p->tope = NULL;
}

int pilaVacia(Pila *p) {
    return p->tope == NULL;
}

void push(Pila *p, char nombre[], char ciudad[], char tema[]) {

    NodoPila *nuevo = (NodoPila *)malloc(sizeof(NodoPila));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->ciudad, ciudad);
    strcpy(nuevo->tema, tema);

    nuevo->sig = p->tope;
    p->tope = nuevo;

    printf("\nParticipante agregado al sorteo.\n");
}

void mostrarPila(Pila *p) {

    if (pilaVacia(p)) {
        printf("\nNo hay participantes en el sorteo.\n");
        return;
    }

    NodoPila *aux = p->tope;

    printf("\n=== PARTICIPANTES DEL SORTEO ===\n");

    while (aux != NULL) {
        printf("\nNombre: %s", aux->nombre);
        printf("\nCiudad: %s", aux->ciudad);
        printf("\nTema: %s\n", aux->tema);

        aux = aux->sig;
    }
}

void pop(Pila *p) {

    if (pilaVacia(p)) {
        printf("\nNo hay participantes para el sorteo.\n");
        return;
    }

    NodoPila *aux = p->tope;

    printf("\nGANADOR DEL SORTEO\n");
    printf("Nombre: %s\n", aux->nombre);
    printf("Ciudad: %s\n", aux->ciudad);
    printf("Tema: %s\n", aux->tema);

    p->tope = aux->sig;
    free(aux);
}

void liberarPila(Pila *p) {

    NodoPila *aux;

    while (p->tope != NULL) {
        aux = p->tope;
        p->tope = p->tope->sig;
        free(aux);
    }
}

void atenderLlamada(Cola *c, Pila *p) {

    if (colaVacia(c)) {
        printf("\nNo hay oyentes en espera.\n");
        return;
    }

    NodoCola *aux = c->frente;

    printf("\n=== ATENDIENDO LLAMADA ===\n");
    printf("Nombre: %s\n", aux->nombre);
    printf("Ciudad: %s\n", aux->ciudad);
    printf("Tema: %s\n", aux->tema);

    int opcion;

    printf("\nDesea participar en el sorteo?\n");
    printf("1. Si\n");
    printf("2. No\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        push(p, aux->nombre, aux->ciudad, aux->tema);
    }

    c->frente = aux->sig;

    if (c->frente == NULL) {
        c->final = NULL;
    }

    free(aux);
}

int main() {

    Cola cola;
    Pila pila;

    inicializarCola(&cola);
    inicializarPila(&pila);

    int opcion;

    do {

        printf("\n\nRADIO EN VIVO\n");
        printf("1. Registrar oyente\n");
        printf("2. Mostrar cola de llamadas\n");
        printf("3. Atender siguiente llamada\n");
        printf("4. Mostrar participantes del sorteo\n");
        printf("5. Seleccionar ganador\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                encolar(&cola);
                break;

            case 2:
                mostrarCola(&cola);
                break;

            case 3:
                atenderLlamada(&cola, &pila);
                break;

            case 4:
                mostrarPila(&pila);
                break;

            case 5:
                pop(&pila);
                break;

            case 6:
                liberarCola(&cola);
                liberarPila(&pila);
                printf("\nMemoria liberada correctamente.\n");
                printf("Programa finalizado.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}