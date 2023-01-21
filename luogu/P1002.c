#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




int main(void)
{
	long long n, m, a, b;
	long long i, j;
	while (scanf("%lld%lld%lld%lld", &n, &m, &a, &b) != EOF)
	{
		n++; m++; a++; b++;
		long long** board = malloc(sizeof(long long*) * (n + 1));
		for (i = 0; i <= n; i++)
		{
			board[i] = malloc(sizeof(long long) * (m + 1));
		}
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++)
				board[i][j] = 0;
		board[1][1] = 1;
		board[a][b] = -1;
		if (a + 1 <= n && b + 2 <= m) board[a + 1][b + 2] = -1;
		if (a + 1 <= n && b - 2 > 0) board[a + 1][b - 2] = -1;

		if (a + 2 <= n && b + 1 <= m) board[a + 2][b + 1] = -1;
		if (a + 2 <= n && b - 1 > 0) board[a + 2][b - 1] = -1;

		if (a - 1 > 0 && b + 2 <= m) board[a - 1][b + 2] = -1;
		if (a - 1 > 0 && b - 2 <= m) board[a - 1][b - 2] = -1;

		if (a - 2 > 0 && b + 1 <= m) board[a - 2][b + 1] = -1;
		if (a - 2 > 0 && b - 1 <= m) board[a - 2][b - 1] = -1;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				if ((i == 1 && j == 1) || (board[i][j] == -1)) continue;
				if (board[i - 1][j] != -1) board[i][j] += board[i - 1][j];
				if (board[i][j - 1] != -1) board[i][j] += board[i][j - 1];
			}




		printf("%lld\n", board[n][m]);
	}


	return 0;
}
