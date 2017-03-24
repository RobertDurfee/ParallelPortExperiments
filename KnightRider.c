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

	while(1)
	{
		for(int i = 0; i < 8; i++)
		{
			outb(pow(2,i), base);
			usleep(50000);
		}
		for(int i = 6; i > 0; i--)
		{
			outb(pow(2,i), base);
			usleep(50000);
		}	
	}

	return 0;
}
