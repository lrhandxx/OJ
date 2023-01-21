#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
	int n;
	int i, j, k;
	int x, y;
	int flag;
	while (scanf("%d", &n) != EOF)
	{
		flag = 0;
		int** carpet = malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++)
		{
			carpet[i] = malloc(sizeof(int) * 4);
			scanf("%d%d%d%d", &carpet[i][0], &carpet[i][1], &carpet[i][2], &carpet[i][3]);
		}
		scanf("%d%d", &x, &y);

		for (i = n - 1; i >= 0; i--)
		{
			if ((x >= carpet[i][0]) && (x <= carpet[i][0] + carpet[i][2]) && (y >= carpet[i][1]) && (y <= carpet[i][1] + carpet[i][3]))
			{
				printf("%d\n", i + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 0) printf("-1\n");
	}


	return 0;
}
