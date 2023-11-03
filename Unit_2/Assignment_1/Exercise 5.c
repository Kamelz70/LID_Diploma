
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c;
	puts("Enter a character:"); 
	scanf("%c",&c);
	printf("ASCII value of %c = %d",c,c);
	return EXIT_SUCCESS;
}
