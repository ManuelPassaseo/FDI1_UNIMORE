#include <stdint.h>

 int* slicing(const int* v, size_t* n, size_t start, size_t end, int step)
{
	 if (v == NULL || n==NULL)return NULL;
	 int size = 0;
	 if (step >= 0)
	 {
		 for (size_t i = start; i <= end; i+=step)
		 {
			 ++size;
		 }
	 }
	 else
	 {
		 for (size_t i = end; i >= start; i+=step)
		 {
			 ++size;
		 }

	 }
	 *n = size;
	 int* ris = malloc(size*sizeof(int));
	 if (step > 0)
	 {
		 for (size_t i = start, j = 0; i <= end; i += step, ++j)
		 {
			 ris[j] = v[i];
		 }
	 }
	 else
	 {
		 for (size_t i = end, j = 0; i >= start; i += step, ++j)
		 {
			 ris[j] = v[i];
		 }
	 }
	 return ris;
}

 int main(void)
 {
	 size_t n = 0;
	 int v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	 int* k = slicing(v,&n, 2 , 6 , -3);
	 free(k);

	 return 0;
 }

