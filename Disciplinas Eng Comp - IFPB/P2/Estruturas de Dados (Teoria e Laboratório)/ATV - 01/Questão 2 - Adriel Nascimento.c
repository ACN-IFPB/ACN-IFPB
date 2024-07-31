/********************************************************************
			INSTITUTO FEDERAL DA PARAÍBA
			CAMPUS DE CAMPINA GRANDE
			ENGENHARIA DA COMPUTAÇÃO
			PROFESSOR: CESAR ROCHA VASCONCELOS
			ALUNO: ADRIEL CASSIMIRO DO NASCIMENTO
			MATRÍCULA: 202021250005
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FUNÇÃO DA QUESTÃO
int* uniao(int *v1, int n1, int *v2, int n2){

	short int x;
	
	v1 = (int*) malloc(sizeof(int)*n1);
	v2 = (int*) malloc(sizeof(int)*n2);
	  
	for (x = 0; x < n1; x++)
		v1[x] = 2*x;
	for (x = 0; x < n2; x++)
		v2[x] = 2*x +1;
	
	int *v3 = (int*) malloc(sizeof(int)*(n1+n2)); //DECLARAÇÃO 
	  
	for (x = 0; x < 5; x++)
		v3[x] = v1[x];
	for (x = 0; x < 5; x++)
		v3[x+5] = v2[x];
	
	return v3;
}

int main(void) {
  
	int *V1, *V2, *V3;
	short int i; 
	
	V3 = uniao( V1,  5,  V2,  5);
	
	for (i = 0; i < 10; i++)
		printf("%d ", V3[i]);
	
	printf("\n");
	
	free(V1);
	free(V2);
	free(V3);
	
	return 0;
}
