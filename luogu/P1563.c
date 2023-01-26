#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




int main(void)
{
	int n, m, i, dest, a, s;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int* array = malloc(sizeof(int) * n);
		char** occupation = malloc(sizeof(char*) * n);
		for (i = 0; i < n; i++)
		{
			occupation[i] = malloc(sizeof(char) * 11);
			scanf("%d%s", &array[i], occupation[i]);
			if (array[i] == 0) array[i] = 1;
			else array[i] = -1;
		}
		dest = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &s);
			if (a == 0) a = -1;
			a *= array[dest];
			dest = (dest + n + s * a) % n;
		}
		printf("%s", occupation[dest]);
	}
	return 0;
}

