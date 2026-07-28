#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "destino.h"

int main()
{
    NodoDestino *listaDestinos = NULL;

    menuPrincipal(&listaDestinos);

    return 0;
}