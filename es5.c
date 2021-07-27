#define  _CRT_SECURE_NO_WARNINGS
#include "variant.h"

void* read_variant(FILE* f, char* type)
{
	if (f == NULL)return NULL;
	int num_read  = fread(type,sizeof(char),1,f);
	if (num_read != 1)
		return NULL;
	if (type[0] != 'c' && type[0] != 's' && type[0] != 'i' && type[0] != 'l' && type[0] != 'f' && type[0] != 'd')
		return NULL;

	else if (type[0] == 'c')
		{

			void* ris = malloc(sizeof(char));
			num_read = fread(ris, sizeof(char), 1, f);
			if (num_read != 1)
			{
				free(ris);
				return NULL;
			}
			return ris;

		}
		else if (type[0] == 's')
		{

			void* ris = malloc(sizeof(short));

			num_read = fread(ris, sizeof(short), 1, f);
			if (num_read != 1)
			{
				free(ris);
				return NULL;
			}

			return ris;

		}
		else if (type[0] == 'i')
		{

			void* ris = malloc(sizeof(int));

			num_read = fread(ris, sizeof(int), 1, f);
			if (num_read != 1)
			{
				free(ris);
				return NULL;
			}

			return ris;

		}
		else if (type[0] == 'l')
		{
			void* ris = malloc(sizeof(long long));

			num_read = fread(ris, sizeof(long long), 1, f);
			if (num_read != 1)
			{
				free(ris);
				return NULL;
			}

			return ris;

		}
		else if (type[0] == 'f')
		{
			void* ris = malloc(sizeof(float));

			num_read = fread(ris, sizeof(float), 1, f);
			if (num_read != 1)
			{
				free(ris);
				return NULL;
			}

			return ris;
		}
		else
		{
			void* ris = malloc(sizeof(double));

			num_read = fread(ris, sizeof(double), 1, f);
			if (num_read != 1)
			{
				free(ris);
				return NULL;
			}
			return ris;

		}

}

int main(void)
{
	FILE* f = fopen("file1.variant","rb");
	char c = 'c';
	read_variant(f,&c);


	return 0;
}