
/*
#include <string.h>
char* rimuovi_singoli_spazi(const char* s)
{
	if (s == NULL || ( s[0]==' ' && strlen(s) == 2 ) )return NULL;
	
	int size = 0;
	for (int i = 0;s[i]!='\0'; ++i)
	{
		int count = 0;
		if (s[i] == ' ' && s[i + 1] == '\0')
		{
			++size;
			break;
		}
	if (s[i] != ' ' && s[i + 1] == ' ' && s[i+2]=='\0'  )
		{
			++size;
		}

		if (s[i]  != ' ' && s[i+1] == ' ' && s[i+2] != ' ')
		{
			++size;
		}	
	}

	char* ris = calloc((strlen(s)-size+1), sizeof(char));
	int j = 0, count = 0, check = 0;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i + 1] == '\0' && s[i]==' ' && s[i-1]== ' ')
		{
			ris[j] = s[i];
			ris[j + 1] = '\0';
			break;
		}
		if(s[i]!= ' ')
		{
			ris[j] = s[i];
			++j;
			continue;
		}

		if(s[i]!=' ' && s[i+1]==' ')
		{
			ris[j] = s[i];
			++j;
			continue;
		}
		if (s[i + 1] == ' ' && s[i]==' ')
		{
			 count = 0;
			for (int k = i;; ++k)
			{
				if (s[k] == ' ')
				{
					ris[j] = s[k];
					++j;
					++count;
				}
				else
				{
					if (count > 0)
					{
						i += count - 1;
						break;
					}
					else
					break;
				}
			}
		}
	}
	return ris;
}
*/
#include <stdint.h>
char* rimuovi_singoli_spazi(const char* s)
{
	if (s == NULL)return NULL;
	
	char* ris = malloc(0);
	int count = 0 ;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] == '\0')
			{
				if (s[i - 1] == ' ')
				{
					ris = realloc(ris,count + 1);
					ris[count] = ' ';
					++count;
				}
				else
				{
					break;
				}
			}


			if (s[i - 1] == ' ' && s[i + 1] == ' ')
			{
				ris = realloc(ris, count + 1);
				ris[count] = ' ';
				++count;
				continue;
			}
			else continue;
		}
		else
		{
			ris = realloc(ris,count + 1);
			ris[count] = s[i];
			++count;
		}


	}
	ris = realloc(ris,count + 1);
	ris[count] = '\0';

	return ris;
}


int main(void)
{
	char * k=rimuovi_singoli_spazi("  abc   def ghi   jkl    mno pqr  s ");
	free(k);

	return 0;
}