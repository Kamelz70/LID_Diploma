
#include <stdio.h>
#include <stdlib.h>
#define X (4 + 3)
#define Y (X + 3)
int main(void) {
	char *px, py;
	int hi = Y;
	px = hi;
	printf("%d", sizeof(py));

	return EXIT_SUCCESS;
}
