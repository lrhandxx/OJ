#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int Check(int i, int j, int** map)
{
	int sum = 0;
	if (map[i - 1][j - 1] == -1) sum++;
	if (map[i - 1][j] == -1) sum++;
	if (map[i - 1][j + 1] == -1) sum++;
	if (map[i][j - 1] == -1) sum++;
	if (map[i][j + 1] == -1) sum++;
	if (map[i + 1][j - 1] == -1) sum++;
	if (map[i + 1][j] == -1) sum++;
	if (map[i + 1][j + 1] == -1) sum++;
	map[i][j] = sum;
	return sum;
}

int main(void)
{
	int n, m;
	int i, j;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		char* s = malloc(sizeof(char) * (m + 2));
		int** map = malloc(sizeof(int*) * (n + 2));
		for (i = 0; i < n + 2; i++)
		{
			map[i] = malloc(sizeof(int) * (m + 2));
			for (j = 0; j < m + 2; j++)
			{
				map[i][j] = 0;
			}
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%s", s);
			for (j = 0; j < m; j++)
			{
				if (s[j] == '*')map[i][j + 1] = -1;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (map[i][j] == -1)
				{
					printf("*");
				}
				else
				{
					Check(i, j, map);
					printf("%d", map[i][j]);
				}

			}
			puts("");
		}
		for (i = 0; i < n + 2; i++)
		{
			free(map[i]);
		}
		free(map);
		free(s);
	}


	return 0;
}
