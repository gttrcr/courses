#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[256];
	fgets(buffer, sizeof(buffer), stdin);
	printf(buffer);
	return 0;
}
