#include <stdint.h>
#include <string.h>
uint8_t* nonogram_row(const char* s, size_t* n)
{
	size_t dim = 0;
	for (size_t i = 0;s[i]!='\0'; ++i)
	{
		if (s[i] == '*' && s[i + 1] == ' ' && s[i - 1] == ' ')
		{
			++dim;
			continue;
		}
		if (s[i] == '*' && (s[i+1] ==' ')||(s[i-1]== ' ' ))
		{
			dim++;
		}
	}
	*n = dim;
	size_t j = 0;
	uint8_t * ris = calloc(dim,sizeof(uint8_t));
	for (size_t i = 0; s[i] != '\0'; ++i)
	{
		for (;j<strlen(s); ++j) 
		{
			if (j == 0 && s[j] == ' ')continue;
			if (s[j] != ' ')
			{
				while (s[j] != '*')
				{
					if (s[j] != '\0')
					{
						ris[i] += 1;
						++j;
					}
					else 
						return ris;
				}
				break;
			}
		}
	}
	return ris;
}


int main(void)
{
	size_t n = 5;
	uint8_t * k= nonogram_row("  *  *** ***    ****",&n);
	free(k);
	return 0;
}