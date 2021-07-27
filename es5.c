#define  _CRT_SECURE_NO_WARNINGS
#include "nonogram.h"
#include <stdio.h>
bool nonogram_load(struct nonogram* ng, const char* filename)
{
	FILE* f = fopen(filename,"r");
	if (f == NULL)return false;
	size_t n = 0;
	int num_read = fscanf(f,"%lu",&n);
	if (num_read == EOF)
	{
		fclose(f);
		return false;
	}
	ng->n = n;

	num_read=fscanf(f,"\n");
	
	if (num_read == EOF)
	{
		fclose(f);
		return false;
	}
	size_t doppio = ng->n * ng->n;
	char* schema = calloc(sizeof(char),(doppio + 1));
	size_t k = 0;
	for (size_t i = 0; i <doppio; ++i)
	{
			for (size_t j = 0; j < n; ++j,++k)
			{
				num_read = fscanf(f, "%c", &schema[k]);
//				if (num_read == EOF)
//					break;
			}
			num_read = fscanf(f, "\n");
	}
	ng->schema = schema;
	fclose(f);
	return true;
}



int main(void)
{

	struct nonogram ng = {1,"asd"};
	bool check = nonogram_load(&ng,"nonogram2.txt");
	return 0;
}