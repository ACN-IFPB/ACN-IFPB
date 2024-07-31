#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <alloc.h>

/* int *uniao (int *v1, int n1, int *v2, int n2); */
/* dados: v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12},*/
/*
int *uniao (int *v1, int n1, int *v2, int n2) {
  int i, *v3, n3 = n1 + n2;
  
  v3 = (int *)malloc(n3 * sizeof(int));
  
  for(i = 0; i < n1; i++) {
      *(v3 + i) = *(v1 + i);
      }
  for(i = 0; i < n2; i++) {
      *(v3 + i + n1) = *(v2 + i);
      }
  return v3;
};

int main() {
  int count, i, n1, n2, *v1 = NULL, *v2 = NULL, *v3 = NULL;
  printf("Insira o tamanho do vetor 1:\n");
  scanf("%d", &n1);
  
  v1 = (int *)calloc(n1 , sizeof(int));
  
  printf("Insira o tamanho do vetor 2:\n");
  scanf("%d", &n2);
  v2 = (int *)malloc(n2 * sizeof(int));
  printf("Agora preencha o vetor 1:\n");
  
  for(count = 0; count < n1; count++) {
      printf("insira o valor da posicao %d do vetor 1:\n", count + 1);
      scanf("%d", (v1 + count));
      }
  printf("Agora preencha o vetor 2:\n");
  for(count = 0; count < n2; count++) {
      printf("insira o valor da posicao %d do vetor 2:\n", count + 1);
      scanf("%d", (v2 + count));
      }
  v3 = (int *)malloc(n1 + n2 * sizeof(int));
  
  v3 = uniao (v1, n1, v2, n2); 
  
  for(i = 0; i < n1 + n2; i++) {
      printf("\n%d", v3[i]); 
      }
	free(v1);
	free(v2);
	free(v3);
return 0;
}

*/

int main (void){
	int x =10;
	printf ("o valor de x eh: %d \n", x);
	int end_x;
	end_x = &x;
	printf ("o valor de end_x eh: %d \n", end_x);
	
	printf ("o valor de &x eh: %d \n", &x);
	
	
	return 0;
}
