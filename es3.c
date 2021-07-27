#include "matrix.h"
double* matrix_snake(const struct matrix* m)
{
	if (m == NULL)return NULL;
	double* ris = malloc(sizeof(double)*m->rows*m->cols);
	size_t i = 0;
	for (size_t r = 0; r < m->rows; ++r)
	{
		for (size_t c = 0; c < m->cols; ++c)
		{
			if (r % 2 == 0)
			{
				ris[i] = m->data[r * m->cols + c];
				++i;
			}
			else
			{
				c = m->cols;
				while (c!=0) {
					--c;
					ris[i] = m->data[r * m->cols + c];
					++i;
					
				}
				break;
			}
		}
	}

	return ris;
}


	
int main(void)
{
	double data[] = {1,2,3,4,5,6,7,8,9,};
	struct matrix m = {3,3,data};
	double * k=matrix_snake(&m);
	free(k);
	return 0;
}