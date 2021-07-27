#include <stdbool.h>
#include <stdint.h>
bool is_arithmetic(const int* v, size_t n)
{
	if (v == NULL || n <= 1)return false;
	if (n == 2)return true;
	size_t count = 0;
	if (n % 2 == 0)
	{
		for (size_t i = 0; i < n; i+=2)
		{
			for (size_t j = 1; j < n; j+=2)
			{
				if (v[i] - v[j] == v[i + 1] - v[j + 1])
					count++;
			}
		}
		if (count == n / 2)
			return true;
		else
			return false;
	}
	else
	{
		for (size_t i = 0; i < n;  i += 2)
		{
			for (size_t j = 1; j < n; j += 2)
			{
				if (j >= n - 1||n==3)
				{
					if (v[i] - v[j] == v[i + 1] - v[0])
					{
						++count;
						goto CHECK;
					}
				}
					if (v[i] - v[j] == v[i + 1] - v[j + 1])
						++count;
					else return false;
			}
		}
CHECK:
		if (count == n / 2)
			return true;
		else
			return false;
	}
}

int main(void)
{
	int v[] = { 3, 3, 3 };
	bool k=is_arithmetic(v,3);

	return 0;
}
