#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define base 0x378

int main(int argc, char **argv)
{
	printf("0x%02x, 0x%02x, 0x%02x\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	if(ioperm(base, 3, 1))
	{
		fprintf(stderr, "Access Denied %x\n", base);
		return 1;
	}

	for(int i = 0; i < 3; i++)
		outb(atoi(argv[i + 1]), base + i);

	return 0;
}
