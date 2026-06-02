/*
Autores:
Loren Dayana Quintero Ramos
Mery Daniela Angulo Sinisterra
KArol Nicol Diaz Silva
Alan Andres Banguera Mina

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONTENEDORES 30
#define BUFFER_SIZE 100

int pesos[MAX_CONTENEDORES];
int cantidad = 0;
int ordenado = 0;

/* Prototipos */
void registrarManual();
void generarAleatorios();
void mostrarContenedores();
void pausar();
int leerEntero(const char *mensaje, int *valor);

/* QuickSort */
void quickSort(int arr[], int inicio, int fin);
int particion(int arr[], int inicio, int fin);

/* MergeSort */
void mergeSort(int arr[], int izquierda, int derecha);
void merge(int arr[], int izquierda, int medio, int derecha);

/* HeapSort */
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);

/* Búsqueda Binaria */
int busquedaBinaria(int arr[], int n, int valor);

/* ===================== PAUSAR ===================== */
void pausar()
{
    char buffer[BUFFER_SIZE];

    printf("\nPresione ENTER para continuar...");
    fgets(buffer, sizeof(buffer), stdin);
}

int leerEntero(const char *mensaje, int *valor)
{
    char buffer[BUFFER_SIZE];

    printf("%s", mensaje);
    if(fgets(buffer, sizeof(buffer), stdin) == NULL)
        return 0;

    if(sscanf(buffer, "%d", valor) != 1)
        return 0;

    return 1;
}

/* ===================== MAIN ===================== */
int main()
{
    int opcion;
    int pesoBuscar;
    int posicion;

    srand(time(NULL));

    do
    {
        printf("\n========================================\n");
        printf("SISTEMA DE ORGANIZACION DE CONTENEDORES\n");
        printf("MUELLE DE CARGA\n");
        printf("========================================\n");
        printf("1. Registrar peso de contenedores manualmente\n");
        printf("2. Generar pesos aleatorios de contenedores\n");
        printf("3. Mostrar contenedores registrados\n");
        printf("4. Ordenar contenedores Metodo 1 (QuickSort)\n");
        printf("5. Ordenar contenedores Metodo 2 (MergeSort)\n");
        printf("6. Ordenar contenedores Metodo 3 (HeapSort)\n");
        printf("7. Buscar contenedor\n");
        printf("8. Salir\n");
        printf("========================================\n");
        if(!leerEntero("Seleccione una opcion: ", &opcion))
        {
            printf("Opcion invalida. Por favor ingrese un numero valido.\n");
            pausar();
            continue;
        }

        switch(opcion)
        {
            case 1:
                registrarManual();
                pausar();
                break;

            case 2:
                generarAleatorios();
                pausar();
                break;

            case 3:
                mostrarContenedores();
                pausar();
                break;

            case 4:
                if(cantidad == 0)
                {
                    printf("No hay contenedores registrados.\n");
                }
                else
                {
                    quickSort(pesos, 0, cantidad - 1);
                    ordenado = 1;
                    printf("Contenedores ordenados con QuickSort.\n");
                    mostrarContenedores();
                }
                pausar();
                break;

            case 5:
                if(cantidad == 0)
                {
                    printf("No hay contenedores registrados.\n");
                }
                else
                {
                    mergeSort(pesos, 0, cantidad - 1);
                    ordenado = 1;
                    printf("Contenedores ordenados con MergeSort.\n");
                    mostrarContenedores();
                }
                pausar();
                break;

            case 6:
                if(cantidad == 0)
                {
                    printf("No hay contenedores registrados.\n");
                }
                else
                {
                    heapSort(pesos, cantidad);
                    ordenado = 1;
                    printf("Contenedores ordenados con HeapSort.\n");
                    mostrarContenedores();
                }
                pausar();
                break;

            case 7:
                if(cantidad == 0)
                {
                    printf("No hay contenedores registrados.\n");
                    pausar();
                    break;
                }

                if(ordenado == 0)
                {
                    printf("Debe ordenar el arreglo antes de buscar.\n");
                    pausar();
                    break;
                }

                if(!leerEntero("Ingrese el peso a buscar: ", &pesoBuscar))
                {
                    printf("Peso invalido.\n");
                    pausar();
                    break;
                }

                posicion = busquedaBinaria(pesos, cantidad, pesoBuscar);

                if(posicion != -1)
                {
                    printf("Contenedor encontrado en la posicion %d.\n", posicion + 1);
                }
                else
                {
                    printf("Peso no encontrado.\n");
                }

                pausar();
                break;

            case 8:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Opcion invalida.\n");
                pausar();
        }

    } while(opcion != 8);

    return 0;
}

/* ===================== REGISTRO MANUAL ===================== */
void registrarManual()
{
    int i;
    char mensaje[BUFFER_SIZE];

    if(!leerEntero("Cantidad de contenedores (1-30): ", &cantidad) || cantidad < 1 || cantidad > MAX_CONTENEDORES)
    {
        printf("Cantidad invalida.\n");
        cantidad = 0;
        return;
    }

    for(i = 0; i < cantidad; i++)
    {
        snprintf(mensaje, sizeof(mensaje), "Peso del contenedor %d: ", i + 1);
        if(!leerEntero(mensaje, &pesos[i]))
        {
            printf("Peso invalido. Intente de nuevo.\n");
            i--;
            continue;
        }
    }

    ordenado = 0;
}

/* ===================== ALEATORIOS ===================== */
void generarAleatorios()
{
    int i;

    if(!leerEntero("Cantidad de contenedores (1-30): ", &cantidad) || cantidad < 1 || cantidad > MAX_CONTENEDORES)
    {
        printf("Cantidad invalida.\n");
        cantidad = 0;
        return;
    }

    for(i = 0; i < cantidad; i++)
    {
        pesos[i] = rand() % 30001 + 1000;
    }

    ordenado = 0;

    printf("Pesos generados correctamente.\n");
}

/* ===================== MOSTRAR ===================== */
void mostrarContenedores()
{
    int i;

    if(cantidad == 0)
    {
        printf("No hay contenedores registrados.\n");
        return;
    }

    printf("\nCONTENEDORES REGISTRADOS\n");

    for(i = 0; i < cantidad; i++)
    {
        printf("Contenedor %d: %d kg\n", i + 1, pesos[i]);
    }
}

/* ===================== QUICKSORT ===================== */
int particion(int arr[], int inicio, int fin)
{
    int pivote = arr[fin];
    int i = inicio - 1;
    int j, temp;

    for(j = inicio; j < fin; j++)
    {
        if(arr[j] < pivote)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[fin];
    arr[fin] = temp;

    return i + 1;
}

void quickSort(int arr[], int inicio, int fin)
{
    if(inicio < fin)
    {
        int pi = particion(arr, inicio, fin);
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fin);
    }
}

/* ===================== MERGESORT ===================== */
void merge(int arr[], int izquierda, int medio, int derecha)
{
    int i, j, k;
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;
    int L[MAX_CONTENEDORES], R[MAX_CONTENEDORES];

    for(i = 0; i < n1; i++)
        L[i] = arr[izquierda + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];

    i = 0;
    j = 0;
    k = izquierda;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int izquierda, int derecha)
{
    if(izquierda < derecha)
    {
        int medio = (izquierda + derecha) / 2;

        mergeSort(arr, izquierda, medio);
        mergeSort(arr, medio + 1, derecha);

        merge(arr, izquierda, medio, derecha);
    }
}

/* ===================== HEAPSORT ===================== */
void heapify(int arr[], int n, int i)
{
    int mayor = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;
    int temp;

    if(izquierda < n && arr[izquierda] > arr[mayor])
        mayor = izquierda;

    if(derecha < n && arr[derecha] > arr[mayor])
        mayor = derecha;

    if(mayor != i)
    {
        temp = arr[i];
        arr[i] = arr[mayor];
        arr[mayor] = temp;

        heapify(arr, n, mayor);
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

/* ===================== BÚSQUEDA BINARIA ===================== */
int busquedaBinaria(int arr[], int n, int valor)
{
    int izquierda = 0;
    int derecha = n - 1;

    while(izquierda <= derecha)
    {
        int medio = (izquierda + derecha) / 2;

        if(arr[medio] == valor)
            return medio;

        if(arr[medio] < valor)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1;
}