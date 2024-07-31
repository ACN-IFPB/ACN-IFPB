#include <stdio.h>

int main (void) {
	short int count = 0;
	
	for (count = 0; count <= 10; count ++ )
		printf ("formula 2*n -1:  %d ", (2*count - 1)) ;
	printf ("\n");
	for (count = 0; count <= 10; count ++ )
		printf ("formula 2*n +1:  %d", 2*count+1);
	
	return 0;
	
}
