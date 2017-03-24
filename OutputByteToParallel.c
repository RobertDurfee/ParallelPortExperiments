#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define base 0x378

int main(int argc, char **argv)
{
	printf("%d\n", atoi(argv[1]));

	if(ioperm(base, 1, 1))
	{
		fprintf(stderr, "Access Denied %x\n", base);
		return 1;
	}

	outb(atoi(argv[1]), base);

	sleep(10000);

	return 0;
}
