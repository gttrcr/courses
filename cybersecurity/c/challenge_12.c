#include <stdio.h>
#include <string.h>

int main()
{
	char username[8];
	char password[8];
	int authenticated = 0;
	//char authenticated = 0; // variante più interessante

	printf("Username: ");
	gets(username);

	printf("Password: ");
	gets(password);

	if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0)
	        authenticated = 1;

	if (authenticated)
		printf("Benvenuto admin!\n");
	else
	printf("Accesso negato.\n");

	return 0;
}
