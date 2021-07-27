#include "matrix.h"

struct matrix* mat_pad(const struct matrix* mat)
{
	if (mat == NULL)return NULL;
	struct matrix* ris = malloc(sizeof(struct matrix ));
	ris->rows = mat->rows * 2 - 1;
	ris->cols = mat->cols * 2 - 1;
	double* data = malloc(sizeof(double)* ris->rows * ris->cols);

	for (size_t r = 0 , row=0; r < ris->rows; ++r, ++row)
	{
		if (r % 2 != 0)
		{
			for (size_t c = 0; c < ris->cols; ++c)
			{
				data[r * ris->cols + c] = 0;
			}
			--row;
		}
		else
		{
			for (size_t c = 0, cols = 0; c < ris->cols; ++c)
			{
				if (c % 2 == 0)
				{
					data[r * ris->cols + c] = mat->data[row * mat->cols + cols];
					++cols;
				}
				else if (c % 2 != 0)
					data[r * ris->cols + c] = 0;
			}
		}
	}
 	ris->data = data;
	return ris;
}

int main(void)
{
	double data[] = {1,2,3,4,5,6,7,8,9};
	struct matrix mat = {3,3,data};

	struct matrix* k = mat_pad(&mat);
	free(k);
	return 0;
}
