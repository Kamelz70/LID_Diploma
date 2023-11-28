
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int y = (1, 2, 3);
	int x = 1;
	y = 1, 2 + x++, 3;
	printf("%d %d", x, y);

	return EXIT_SUCCESS;
}
