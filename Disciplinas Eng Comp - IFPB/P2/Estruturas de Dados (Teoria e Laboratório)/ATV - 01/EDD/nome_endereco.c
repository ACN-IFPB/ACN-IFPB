#include <stdio.h>
#include <stdlib.h>

void limpa_buffer (void){
}
int main (void) {
	char local [31] ;
	char nome [41];
	
	printf ("entre com seu nome e seu endereco:\n");
	scanf ("%s", &nome);
	limpa_buffer();
	scanf ("%s", &local);
	printf ("%s\n%s", &nome, &local);
	return 0;
}
