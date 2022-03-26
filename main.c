#include <stdio.h>

int assitoa(int src, int sgn, char* stringa);

int main(void)
{
	char stringa[255];

	printf("%d",assitoa(123, 0, stringa));
	printf("\n%c%c%c", stringa[0],stringa[1],stringa[2]);

	return 0;
}

