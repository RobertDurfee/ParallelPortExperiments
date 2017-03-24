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

	unsigned char dataPort = inb(base + 0);
	unsigned char dataBits[8];
	for(int i = 0; i < 8; i++)
		dataBits[i] = (dataPort >> i) & 0x01;
	
	unsigned char statusPort = inb(base + 1);
	unsigned char statusBits[8];
	for(int i = 0; i < 8; i++)
		statusBits[i] = (statusPort >> i) & 0x01;
		
	unsigned char controlPort = inb(base + 2);
	unsigned char controlBits[8];
	for(int i = 0; i < 8; i++)
		controlBits[i] = (controlPort >> i) & 0x01;
	
	printf("\nDataPort (0x%02x):\t", dataPort);
	for(int i = 7; i >= 0; i--)
		printf("%d ", dataBits[i]);

	printf("\n\nStatusPort (0x%02x):\t", statusPort);
	for(int i = 7; i >= 0; i--)
		printf("%d ", statusBits[i]);

		printf("\n\n 7. BUSY:\t\t%d*\n", statusBits[7]);
		printf(" 6. ACK:\t\t%d\n", statusBits[6]);
		printf(" 5. PAPER OUT:\t\t%d\n", statusBits[5]);
		printf(" 4. SELECT IN:\t\t%d\n", statusBits[4]);
		printf(" 3. ERROR:\t\t%d\n", statusBits[3]);
		printf(" 2. IRQ:\t\t%d\n", statusBits[2]);
		printf(" 1. Reserved:\t\t%d\n", statusBits[1]);
		printf(" 0. Reserved:\t\t%d", statusBits[0]);

	printf("\n\nControlPort (0x%02x):\t", controlPort);
	for(int i = 7; i >= 0; i--)
		printf("%d ", controlBits[i]);

		printf("\n\n 7. UNUSED:\t\t\t%d\n", controlBits[7]);
		printf(" 6. UNUSED:\t\t\t%d\n", controlBits[6]);
		printf(" 5. ENABLE BI-DIRECTIONAL PORT:\t%d\n", controlBits[5]);
		printf(" 4. ENABLE IRQ VIA ACK LINE:\t%d\n", controlBits[4]);
		printf(" 3. SELECT PRINTER:\t\t%d*\n", controlBits[3]);
		printf(" 2. INITIALIZE PRINTER:\t\t%d\n", controlBits[2]);
		printf(" 1. AUTO LINEFEED:\t\t%d*\n", controlBits[1]);
		printf(" 0. STROBE:\t\t\t%d*\n", controlBits[0]);
	
	printf("\n");

	return 0;
}
