#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main()
{
    ListaDestino listaDestinos;

    inicializarLista(&listaDestinos);

    menuPrincipal(&listaDestinos);

    liberarDestinos(&listaDestinos);

    return 0;
}
