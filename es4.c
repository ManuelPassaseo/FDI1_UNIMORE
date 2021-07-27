#include <stdint.h>
#include <string.h>
#include <stdbool.h>
void bad_word_filter(char* s, char** words, size_t nwords)
{
	if (s == NULL || nwords == 0 || words == NULL)return;
	int count = 0;
	int index = 0;

	for (size_t k = 0; k < nwords; ++k)
	{
		for (int i = 0; s[i] != '\0'; ++i) 
		{
			count = 0;

			for (int j = 0;s[i]!='\0'; ++i)
			{
				if (s[i] == words[k][j])
				{
					++count;
					++j;
				}
				if (count == strlen(words[k]))
				{
					index = i - count + 1;
					for (int l = 0; l < strlen(words[k]); l++)
					{
						s[index + l] = '*';
					}
				}

			}
		}
	}
}

int main(void)
{
	char* words[] = { "carciofo", "broccolo", "cavolfiore" };
	bad_word_filter("sei un broccolo",words,3);
	return 0;
}