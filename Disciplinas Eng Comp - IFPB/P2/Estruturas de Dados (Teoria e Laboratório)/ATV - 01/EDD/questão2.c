#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* dados: v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12},*/

int *uniao(int *v1, int n1, int *v2, int n2){

	int soma = n1 + n2;
	int i=0;
	int *v3 = (int *) malloc(soma * sizeof(int));

	for(i = 0; i < n1; i++)
		*(v3+i) = *(v1+i);
	
	for(i = 3; i < (soma-n1); i++)
		*(v3+i) = *(v2+i);
	return v3;
}

int main(void){

	int v1[4], v2[6], v3[10], n1, n2;
	int count1, count2, count3;
	v1[0] = 0;
	v2[0] = 0;
	v3 [0]= 0;
	
	for (count1 =0 ; count1 < 4; count1++){
		printf("Digite os valores para o vetor 1: ");
		scanf("%d", v1[count1]);
	}

	for(count2 = 0; count2 <6; count2++){
		printf("Digite os valores para o vetor 2: ");
		scanf("%d", v2[count2]);
	}

	v3 = uniao(v1, 4, v2, 6);
	
	for(count3 = 0; count3 < 10; count3++){
		printf("%d\n", *(v3+count3));
	}

	free(v3);
	return 0;
} 
