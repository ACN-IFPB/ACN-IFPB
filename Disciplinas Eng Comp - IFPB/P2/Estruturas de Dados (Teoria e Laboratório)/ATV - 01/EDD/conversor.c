#include <stdio.h>
#include <stdlib.h>

int main (void){
    float pol;
    printf ("Entre com o valor em polegadas \n");
    scanf ("%f", &pol);
    pol = pol*2,54;
    printf ("O valor em centimetros eh: %2.f\n", pol);
    return 0;
}
