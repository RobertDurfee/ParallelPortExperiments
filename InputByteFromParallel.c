#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <math.h>

#define base 0x378

int main()
{
	if(ioperm(base, 1, 1))
	{
		fprintf(stderr, "Access Denied %x\n", base);
		return 1;
	}

	printf("%d", inb(base));

	return 0;
}
