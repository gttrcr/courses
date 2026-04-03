//gcc -Wall -Wextra -o safe_builtin safe_alloc_builtin.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *alloca_array_sicura(size_t n, size_t elem_size)
{
	size_t sz;
	if (__builtin_mul_overflow(n, elem_size, &sz))
	{
		fprintf(stderr, "[ERRORE] overflow: n=%zu * elem_size=%zu supera SIZE_MAX\n", n, elem_size);
		return NULL;
    	}

	void *ptr = malloc(sz);
	if (!ptr)
	{
        	fprintf(stderr, "[ERRORE] malloc(%zu) fallita\n", sz);
		return NULL;
    	}
	return ptr;
}

static void test(const char *label, size_t n) {
    printf("\n--- %s (n = %zu) ---\n", label, n);

    int *arr = alloca_array_sicura(n, sizeof(int));
    if (!arr) {
        printf("  Allocazione bloccata correttamente.\n");
        return;
    }

    /* usa l'array in modo sicuro */
    for (size_t i = 0; i < n; i++)
        arr[i] = (int)i * 2;

    printf("  Allocati %zu int. arr[0]=%d, arr[%zu]=%d\n",
           n, arr[0], n - 1, arr[n - 1]);

    free(arr);
    printf("  Memoria liberata.\n");
}

int main(void)
{
	printf("=== Test __builtin_mul_overflow ===\n");
	test("caso normale",      10);
	test("caso limite basso", 1);
	test("massimo sicuro",    SIZE_MAX / sizeof(int));      /* soglia esatta */
	test("overflow per 1",   (SIZE_MAX / sizeof(int)) + 1); /* deve fallire */
	test("overflow estremo",  SIZE_MAX);                    /* deve fallire */

	return 0;
}
