#include <stdlib.h>
#include <stdio.h>
int main()
{
	int *ptr = malloc(sizeof(int));
	*ptr = 42;
	free(ptr);
	printf("%d\n", *ptr);
}
