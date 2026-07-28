#include <stdio.h>
#include <math.h>
#include "areas.h"
#include "volumenes.h"


double areaCirculo(double radio) {
    return 3.1416 * radio * radio;  
}

double areaCuadrado(double lado) {
    return lado * lado;
}


double volumenEsfera(double radio) {
    return (4.0/3.0) * 3.1416 * radio * radio * radio;
}

double volumenCubo(double lado) {
    return lado * lado * lado;
}

int main() {
    double r, l;

    printf("Ingrese el radio del circulo: ");
    scanf("%lf", &r);
    printf("Area del circulo: %.2lf\n", areaCirculo(r));

    printf("Ingrese el lado del cuadrado: ");
    scanf("%lf", &l);
    printf("Area del cuadrado: %.2lf\n", areaCuadrado(l));

    printf("Ingrese el radio de la esfera: ");
    scanf("%lf", &r);
    printf("Volumen de la esfera: %.2lf\n", volumenEsfera(r));

    printf("Ingrese el lado del cubo: ");
    scanf("%lf", &l);
    printf("Volumen del cubo: %.2lf\n", volumenCubo(l));

    return 0;
}