#include <string.h>
char* change_font(const char* s)
{
	if (s == NULL)return NULL;

	char* ris = calloc((strlen(s) + 1),sizeof(char));

	for (int i = 0,j=0; s[i] != '\0'; ++i,++j)
	{
		if (s[i] == 'S' && s[i + 1] == 'E' && s[i + 2] == 'I')
		{
			ris[j] = '6';
			i += 2;
			continue;
		}
		else if (s[i] == 'P' && s[i + 1] == 'E' && s[i + 2] == 'R') {
			ris[j] = 'X';
			i += 2;

			continue;
		}
		else if (s[i] == 'A')
		{
			ris[j] = '4';
			continue;
		}
		else if (s[i] == 'E')
		{
			ris[j] = '3';
			continue;
		}
		else if (s[i] == 'I')
		{
			ris[j] = '1';
			continue;
		}
		else if (s[i] == 'O')
		{
			ris[j] = '0';
			continue;
		}
		else if (s[i] == 'S')
		{
			ris[j] = '5';
			continue;
		}
		else
			ris[j] = s[i];
	}

	return ris;
}


int main(void)
{

	char * k=change_font("QUATTRO PAPERE VISITARONO SEI MUSEI");
	free(k);

	return 0;
}