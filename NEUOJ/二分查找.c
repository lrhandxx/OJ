#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	int n, q, k,i,t,min,max;
	while (scanf("%d", &n) != EOF)
	{
		int* a = malloc(sizeof(int) * n);
		k = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%d", &q);
		for (i = 0; i < q; i++)
		{
			scanf("%d", &t);
			min = 0; max = n - 1;
			while (min <= max)
			{
				if (a[(min + max) / 2] != t)
				{
					if (a[(min + max) / 2] > t)
					{
						max = (min + max) / 2 - 1;
					}
					else
					{
						min= (min + max) / 2 + 1;
					}
				}
				else
				{
					k++;
					break;
				}
			}

		}
		printf("%d\n", k);
		free(a);
	}
	return 0;
}
