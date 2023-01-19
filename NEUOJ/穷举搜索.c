#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Recursion(int i, int* sum, int* a, int* mi)
{
	int a1[2] = { sum[0],sum[0] + a[i] };
	int a2[2] = { sum[1],sum[1] + a[i] };
	mi[sum[0] + a[i]] = 1;
	mi[sum[1] + a[i]] = 1;
	if (i != 0)
	{
		Recursion(i - 1, a1, a, mi);
		Recursion(i - 1, a2, a, mi);
	}
}

int main(void)
{
	int n, i,q;
	while (scanf("%d", &n) != EOF)
	{
		int* a = malloc(sizeof(int) * n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int mi[40005] = { 0 };
		int ar[2] = {0};
		Recursion(n - 1, ar, a, mi);
		scanf("%d", &q);
		while (q-- != 0)
		{
			scanf("%d", &i);
			if (mi[i] == 1) puts("yes");
			else puts("no");
		}
	}

	return 0;
}