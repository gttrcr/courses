#include <stdio.h>
#include <string.h>
int main()
{
	char buffer[10];
	printf("Inserisci qualcosa: ");
	gets(buffer);
	printf("Hai scritto: %s\n", buffer);
	return 0;
}
