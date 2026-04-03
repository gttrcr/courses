#include<stdio.h>
#include<stdlib.h>

int main()
{
	char buf[256];
	fgets(buf, sizeof(buf), stdin);
	printf(buf);
}

