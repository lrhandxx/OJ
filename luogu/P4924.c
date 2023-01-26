#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Rotate(int** a, int x, int y, int r, int z)
{
	int i, j;
	int n1, n2, n3, n4;

	for (i = r; i > 0; i--)
	{
		for (j = r; j >= 0; j--)
		{
			n1 = a[x - i][y - j];
			n2 = a[x - j][y + i];
			n3 = a[x + i][y + j];
			n4 = a[x + j][y - i];
			if (z == 0)
			{
				a[x - i][y - j] = n4;
				a[x - j][y + i] = n1;
				a[x + i][y + j] = n2;
				a[x + j][y - i] = n3;
			}
			else
			{
				a[x - i][y - j] = n2;
				a[x - j][y + i] = n3;
				a[x + i][y + j] = n4;
				a[x + j][y - i] = n1;
			}
		}
	}

}

int main(void)
{
	int n, m, i, j, k;
	int x, y, r, z;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int** array = malloc(sizeof(int*) * n);
		k = 0;
		for (i = 0; i < n; i++)
		{
			array[i] = malloc(sizeof(int) * n);
			for (j = 0; j < n; j++)
			{
				k++;
				array[i][j] = k;
			}
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d%d", &x, &y, &r, &z);
			Rotate(array, x - 1, y - 1, r, z);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d ", array[i][j]);
			}
			puts("");
		}
	}
	return 0;
}

