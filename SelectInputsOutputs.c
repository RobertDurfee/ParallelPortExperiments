#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <math.h>

#define base 0x378

int main(int argc, char **argv)
{
	if(ioperm(base, 3, 1))
	{
		fprintf(stderr, "Access Denied %x\n", base);
		return 1;
	}

	int selection = atoi(argv[1]);

	if(atoi(argv[1]) < 0x0E) selection |= 0x20;

	selection ^= 0x0B;

	outb(selection, base + 0x02);

	if(atoi(argv[1]) >= 0x0E) outb(atoi(argv[2]), base + 0);

	unsigned char dataPort = inb(base + 0);

	unsigned char dataBits[8];
	for(int i = 0; i < 8; i++)
		dataBits[i] = (dataPort >> i) & 0x01;

	printf("DataPort (0x%02x):\t", dataPort);
	for(int i = 7; i >= 0; i--)
		printf("%d ", dataBits[i]);

	printf("\n");
	
	return 0;
}
