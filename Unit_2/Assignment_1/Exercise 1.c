
#include <stdio.h>
#include <stdlib.h>
#define X (4 + 3)
#define Y (X + 3)
typedef struct emp
{
} employee;
int main(void) {
	// employee a = {"ahmed", 5000};
	// a.salary = 300;
	// printf("sssssssssssss", a.salary);

	int Arr[5] = {1, 2, 3};
	int(*LonArr)[5] = &Arr;
	printf("%d", *((*LonArr) + 1));
	// printf("%d", a.salary);

	return EXIT_SUCCESS;
}
