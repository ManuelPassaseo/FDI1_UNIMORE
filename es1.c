#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_table(char** colnames, uint8_t ncols, uint8_t nrows)
{
	printf("|");
	fprintf(stdout, "%s", *colnames);
	int dim;
	dim = strlen(colnames);

	for (int i = 0;i<strlen(colnames); ++i)
	{
		
		++colnames;

	}
}




int main(void)
{
	char* s[] = { "cat", "dog","deer", "frog"};
	print_table(s,4,2);
	return 0;
}