#include <stdio.h>
#include <string.h>
int main()
{
	char buffer[8];
	int is_admin = 0;
	gets(buffer);
	if (is_admin)
		printf("Accesso admin!\n");
	else
		printf("Accesso normale.\n");
	return 0;
}
