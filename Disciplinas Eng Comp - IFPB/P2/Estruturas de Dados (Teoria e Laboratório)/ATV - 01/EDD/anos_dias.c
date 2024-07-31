#include <stdio.h>

int main(void){
	short int idade;
	printf("diga sua idade:");
	scanf("%d",&idade);	
	printf("%d anos equivalem a: %d days", idade, (idade*365));
	
	return 0;
}

