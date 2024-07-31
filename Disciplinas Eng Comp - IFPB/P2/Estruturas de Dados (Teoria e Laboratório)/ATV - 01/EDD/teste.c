# include <stdio.h>
#include <stdlib.h>

struct Ponto {
	float x, y;
};

int main (void){
	struct Ponto p1, p2;
	p1.x = 5;
	p1.y = 4;
	printf ("%.2f, %.2f", p1.x, p1.y);
	return 0;
}
