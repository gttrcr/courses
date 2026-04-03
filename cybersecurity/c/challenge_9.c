#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	size_t n = (size_t)atoi(argv[1]);
	size_t alloc_size = n * sizeof(int);

	printf("n            = %zu\n", n);
	printf("sizeof(int)  = %zu\n", sizeof(int));
	printf("alloc_size   = %zu  (0x%zx)\n", alloc_size, alloc_size);

	// Sorgente di dati: 16 byte innocui
	char src[16] = "AAAABBBBCCCCDDDD";
	char *buf = malloc(alloc_size);
	if (!buf)
	{
        	printf("malloc fallita (size troppo grande o overflow evidente)\n");
		return 1;
	}

	printf("buf allocato a: %p  (size richiesta: %zu byte)\n", (void*)buf, alloc_size);
	memcpy(buf, src, n * sizeof(int));
	printf("memcpy completata (o crash avvenuto sopra)\n");
	free(buf);
	return 0;
}
