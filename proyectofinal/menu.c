#include "menu.h"


void menuPrincipal(ListaDestino *lista)
{
    int opcion;


    do
    {
        printf("\n======================================");
        printf("\n TERMINAL PORTUARIO TURISTICO");
        printf("\n======================================");

        printf("\n1. Registrar destino");
        printf("\n2. Registrar pasajero");
        printf("\n3. Mostrar pasajeros por destino");
        printf("\n4. Registrar viaje programado");
        printf("\n5. Buscar viaje");
        printf("\n6. Mostrar arbol de viajes");
        printf("\n7. Realizar embarque");
        printf("\n8. Consultar pasajero");
        printf("\n9. Mostrar estadisticas");
        printf("\n0. Salir");

        printf("\n\nSeleccione una opcion: ");
        scanf("%d",&opcion);



        switch(opcion)
        {

            case 1:

                registrarDestino(lista);

                break;



            case 2:

                registrarPasajero(lista);

                break;



            case 3:

                mostrarPasajerosDestino(lista);

                break;



            case 4:

                registrarViaje(lista);

                break;



            case 5:
            {
                int codigoDestino;
                int codigoViaje;

                NodoDestino *destino;
                NodoViaje *viaje;


                printf("\nCodigo del destino: ");
                scanf("%d",&codigoDestino);


                destino = buscarDestino(lista,codigoDestino);


                if(destino == NULL)
                {
                    printf("\nDestino no encontrado.\n");
                    break;
                }


                printf("Codigo del viaje: ");
                scanf("%d",&codigoViaje);


                viaje = buscarViaje(destino->raizViajes,codigoViaje);



                if(viaje != NULL)
                {
                    printf("\nViaje encontrado:");
                    printf("\nCodigo: %d",viaje->codigoViaje);
                    printf("\nFecha: %s",viaje->fecha);
                    printf("\nCapacidad: %d\n",viaje->capacidad);
                }
                else
                {
                    printf("\nViaje no encontrado.\n");
                }


                break;
            }



            case 6:
            {
                int codigoDestino;

                NodoDestino *destino;


                printf("\nCodigo del destino: ");
                scanf("%d",&codigoDestino);



                destino = buscarDestino(lista,codigoDestino);



                if(destino == NULL)
                {
                    printf("\nDestino no encontrado.\n");
                }
                else
                {
                    printf("\n--- ARBOL DE VIAJES ---\n");

                    mostrarInorden(destino->raizViajes);
                }


                break;
            }




            case 7:

                embarcarPasajero(lista);

                break;




            case 8:

                consultarPasajero(lista);

                break;



            case 9:

                mostrarEstadisticas(lista);

                break;



            case 0:

                printf("\nCerrando sistema...\n");

                break;



            default:

                printf("\nOpcion invalida.\n");

        }


    }while(opcion != 0);

}