#define _CRT_SECURE_NO_WARNINGS
#include "product.h"

void write_products(FILE* f, const struct product* list, size_t n)
{
	if (list == NULL || f == NULL)return;
	if (n == 0)
	{
		fprintf(f, "[\n");
		fprintf(f, "]");
		return;
	}
	int num_read = 0;
	fprintf(f,"[\n");

	for (size_t i = 0; i < n; ++i)
	{
		if (i == n - 1)
		{
			fprintf(f, "\t{\n");

			num_read = fprintf(f, "\t\t\"productId\": \"%s\",\n", list[i].productId);
			num_read = fprintf(f, "\t\t\"fullName\": \"%s\",\n", list[i].fullName);
			num_read = fprintf(f, "\t\t\"price\": %i\n", list[i].price);
			fprintf(f, "\t}\n");
			break;
		}
		else
		{
			fprintf(f, "\t{\n");

			num_read=fprintf(f, "\t\t\"productId\": \"%s\",\n"  ,list[i].productId);
			num_read = fprintf(f, "\t\t\"fullName\": \"%s\",\n"  , list[i].fullName);
			num_read = fprintf(f, "\t\t\"price\": %i\n"  , list[i].price);
			fprintf(f, "\t},\n");
		}

	}
 	fprintf(f, "]");
}



int main(void)
{
	struct product list = {"ID", "FULLNAME",3321};
	FILE* f = fopen("test1.txt","w");
	write_products(f,&list,1);

	fclose(f);
	return 0;
}