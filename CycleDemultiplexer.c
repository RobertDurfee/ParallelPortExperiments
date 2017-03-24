#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <math.h>

#define base 0x378

int main()
{
	if(ioperm(base, 3, 1))
	{
		fprintf(stderr, "Access Denied %x\n", base);
		return 1;
	}

	int start[4] = {11, 15, 3, 7};

	while(1)
	{
		for(int j = 0; j < 4; j++)
			for(int i = start[j]; i > start[j] - 4; i--)
			{
				outb(i, base + 2);
				usleep(25000);
			}
		for(int j = 3; j >= 0; j--)
			for(int i = start[j] - 3; i < start[j]; i++)
			{
				outb(i, base + 2);
				usleep(25000);
			}
	}
	
	return 0;
}
