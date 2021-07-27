#include <stdint.h>
#include <stdbool.h>
size_t find_first_partition(const int* seq, size_t n)
{
	if (seq == NULL || n == 0)return 0;

	size_t k;
	int  max = seq[0];
	for (size_t i = 0; i < n; ++i)
	{
		bool check = false;
		if (i == 0)
		{
			check = true;
		}
		for(size_t j = 1; j < n ; ++j)
		{
			if (i != 0) 
			{
				if (max < seq[j])
				{
					max = seq[j];
					check = true;
				}
			}
			if (check == true)
			{
				for ( k = n -1  ; k > j; --k)
				{
					if (max > seq[k])
						break;
				}
				if (k == j && i!=0)
				{
					return k;
				}
				if (j == k && i == 0)
				{
					if (max == seq[k])
						break;
					return 0;
				}
				break;
			}
		}
	}

	return n;
}


int main(void)
{
	int seq[] = { -9, -7, -10, -8, -9, -6, 4, 3, 6, 8, 10, 7, 9 };
	size_t k=find_first_partition(seq,13);
	
	return 0;
}