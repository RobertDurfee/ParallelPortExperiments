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
	
	printf("Select (0x%01x):\t", atoi(argv[1]));
	unsigned char function_select_bits[4];
	for(int i = 0; i < 4; i++)
		function_select_bits[i] = (atoi(argv[1]) >> i) & 0x01;
	for(int i = 3; i >= 0; i--)
		printf("%d ", function_select_bits[i]);

	printf("\nA (0x%01x):\t", atoi(argv[2]));
	unsigned char A_bits[4];
	for(int i = 0; i < 4; i++)
		A_bits[i] = (atoi(argv[2]) >> i) & 0x01;
	for(int i = 3; i >= 0; i--)
		printf("%d ", A_bits[i]);

	printf("\nB (0x%01x):\t", atoi(argv[3]));
	unsigned char B_bits[4];
	for(int i = 0; i < 4; i++)
		B_bits[i] = (atoi(argv[3]) >> i) & 0x01;
	for(int i = 3; i >= 0; i--)
		printf("%d ", B_bits[i]);

	int function_select = (atoi(argv[1]) & 0x0F) ^ 0x0B;
	
	int A = (~atoi(argv[2])) & 0x0F;
	int B = (~atoi(argv[3])) & 0x0F;

	int function_input = (B << 4) | A;

	outb(function_select, base + 0x02);
	
	outb(function_input, base + 0x00);

	int function_output = ~((inb(base + 0x01) >> 3)) & 0x0F;
	
	printf("\nResult (0x%01x):\t", function_output);
	unsigned char function_output_bits[4];
	for(int i = 0; i < 4; i++)
		function_output_bits[i] = (function_output >> i) & 0x01;
	for(int i = 3; i >= 0; i--)
		printf("%d ", function_output_bits[i]);

	printf("\n");

	return 0;
}
