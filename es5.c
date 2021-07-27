#define _CRT_SECURE_NO_WARNINGS
#include "read_dvec.h"
#include <math.h>
#include <stdio.h>

struct dvec* read_dvec_comp(const char* filename)
{
	struct dvec* ris = malloc(sizeof(struct dvec));
	FILE* f = fopen(filename,"rb");
	if (f == NULL)
	{
		ris->d = NULL;
		ris->n = 0;
		return ris;
	}

	size_t n = 0;
	int num_read = 0, size = 0;

	while (1)
	{
		num_read = fread(&n,sizeof(int16_t),1,f);
		if (num_read != 1)break;
		++size;
	}
	rewind(f);
	ris->n = size;

	double* d = calloc(size,sizeof(double));
	for (int i = 0;i<size; ++i)
	{
		int16_t c = 0;
		num_read = fread(&c, sizeof(int16_t), 1, f);
		if (num_read != 1)
		{
			ris->d = NULL;
			ris->n = 0;
			fclose(f);
			return ris;
		}
		d[i] = ( c / pow(2,14) );
	}

	ris->d = d;
	fclose(f);

	return ris;
}



int main(void)
{
	struct dvec * k=read_dvec_comp("1.dvec");
	free(k);

	return 0;
}