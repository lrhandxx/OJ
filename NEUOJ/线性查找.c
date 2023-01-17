#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	int n, q, k,i,j,t;
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
			for (j = 0; j < n; j++)
			{
				if (t == a[j])
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
