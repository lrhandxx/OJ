#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int Check(int n, int k, int* wi, int P)
{
	int i, t = P;
	k--;
	for (i = 0; i < n; i++)
	{
		if (t >= wi[i])
		{
			t -= wi[i];
		}
		else
		{
			if (k > 0)
			{
				k--;
				t = P-wi[i];
				if (t < 0) return 0;
				
			}
			else return 0;
		}
	}
	return 1;
}

int main(void)
{
	int n, k, i;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		int* wi = malloc(sizeof(int) * n);
		int sum = 0, min, max, mid;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &wi[i]);
			sum += wi[i];
		}
		min = sum / k;
		max = sum;
		while (min < max)
		{
			mid = (max + min) / 2;
			if (Check(n, k, wi, mid) == 1)
			{
				max = mid;
			}
			else min = mid + 1;
		}
		printf("%d", min);
		free(wi);
	}

	return 0;
}