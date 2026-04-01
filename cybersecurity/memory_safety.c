#include <stdio.h>
#include <string.h>
int main()
{
	char buffer[1];
	printf("Inserisci qualcosa: ");
	gets(buffer);
	for(int i=0; i<100; i++)
		printf("%c", *(buffer+i));

	printf("%d\n", &buffer);
	//fgets(buffer, sizeof(buffer), stdin);
	//printf("Hai scritto: %s\n", buffer);
	return 0;
}
