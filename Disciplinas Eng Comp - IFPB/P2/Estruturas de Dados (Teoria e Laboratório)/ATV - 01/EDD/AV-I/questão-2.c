#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* dados: v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12},*/

int *uniao(int *v1, int n1, int *v2, int n2){
    int i = 0;
	int soma = n1 + n2;
	
	int *v3 = (int *) malloc(soma * sizeof(int));

	for(i = 0; i < n1; i++)
		v3[i] = v1[i];

	for(i = 0; i < (n2); i++)
		v3[i+n1] = v2[i];
	return v3;
}

int main(void){

	int *v1, *v2;
	int count1, count2, count3;
	
	
	v1 = (int*) malloc(sizeof(int)*4);
  	v2 = (int*) malloc(sizeof(int)*6);
	
	for (count1 = 0 ; count1 < 4; count1++){
		v1[count1] = count1 + 1 ;
	}

	for(count2 = 0; count2 < 6; count2++){
		v2[count2] = count2 + 5 ;
	}

	
	int *v3 = uniao(v1,4,v2,6);

	for(count3 = 0; count3 < 10; count3++){
		printf("%d\n", v3[count3] );
	}
	free(v1);
	free(v2);
	free(v3);
	
	return 0;
}