#include <stdio.h>
#define SURNAME "Paula"
#define LNAME "Tejano"

void main(void)
{
	printf("%s %s\n", SURNAME, LNAME);
	printf("%s\n%s\n", SURNAME, LNAME);
	printf("%s ", SURNAME);
	printf("%s\n", LNAME);
}
