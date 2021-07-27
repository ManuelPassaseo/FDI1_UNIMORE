#include "matrix.h"
struct vector* mat_vectorize(const struct matrix* m, enum vectorize_by dir)
{
	if (m == NULL)return NULL;
	struct vector* v = malloc(sizeof(double)*m->rows*m->cols);
	v->n = m->rows*m->cols;
	double * data= malloc(sizeof(double) * m->rows * m->cols);
	if (v == NULL)return NULL;
	if (dir == BY_ROW) 
	{
		for (size_t r = 0; r < m->rows; ++r)
		{
			for (size_t c = 0; c < m->cols; ++c)
			{
				data[r*m->cols + c] = m->data[r*m->cols+c];
			}
		}
	}
	else
	{
		size_t i = 0;
		{
			for (size_t c = 0; c < m->cols; ++c)
			{
				for (size_t r = 0; r < m->rows; ++r)
				{
					data[i] = m->data[r * m->cols + c];
					++i;
				}
			}
		}

	}
	v->data = data;
	return v;
}

int main(void)
{
	double data[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	struct matrix m = {3,4,data};

	struct vector *k=mat_vectorize(&m,BY_COLUMN);
	free(k);
	return 0;
}