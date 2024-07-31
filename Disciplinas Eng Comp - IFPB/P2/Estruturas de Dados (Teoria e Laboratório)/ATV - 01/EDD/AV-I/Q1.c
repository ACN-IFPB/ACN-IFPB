#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct ponto { 
    float x, y; 
};


typedef struct circulo {
    
    char *nome;
    struct ponto a, b;  // o centro é definido como pontos a, b; 
    float raio; 
};

void le_ponto(struct ponto *p, char *);
    float dist(struct ponto p1, struct ponto p2);

int criaCirculo (string, centro, r){
    struct circulo (nome,ponto, raio);
    return *C;
};

contem(){

};

int main (void){

/*    Circulo *c1, *c2, *c3;
    c1 = criaCirculo ("Circulo01", 3.0, 4.0,2.0);
    c2 = criaCirculo ("Circulo02", 3.0, 3.0,1.0);
    c3 = criaCirculo ("Circulo03", 1.0, 5.0,1.0);
*/


    struct ponto p1, p2;
    printf("\nDistancia entre os pontos:\n");
    le_ponto(&p1, "primeiro");
    le_ponto(&p2, "segundo");
    printf("\n\nDistancia entre os pontos: %5.2f\n", dist(p1, p2));
}
void le_ponto(struct ponto *p, char *s)
{
    int x, y;
    printf("Digite as coordenadas do %s ponto (x,y): ", s);
    scanf("%d%d", &x, &y);
    p->x = x;
    p->y = y;
}
float dist(struct ponto p1, struct ponto p2)
{
    float s1, s2;
    s1 = pow((p1.x-p2.x), 2);   /* Funcao pow(x,y) retorna x^y */
    s2 = pow((p1.y-p2.y), 2);
    return sqrt( s1 + s2);    /* Funcao sqrt(x) retorna a raiz quadrada de x */

return 0;
}