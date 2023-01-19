#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define cos60 (0.5)
#define sin60 (sqrt(3)/2)

typedef struct
{
	double x;
	double y;
} Point;

void Recursion(int n, Point p1, Point p2)
{
	Point s, u, t, AB;

	if (n == 0) printf("%.8lf %.8lf\n", p1.x, p1.y);
	else
	{
		s.x = (p2.x - p1.x) / 3 + p1.x;
		s.y = (p2.y - p1.y) / 3 + p1.y;
		t.x = (p2.x - p1.x) / 3 * 2 + p1.x;
		t.y = (p2.y - p1.y) / 3 * 2 + p1.y;
		AB.x = t.x - s.x;
		AB.y = t.y - s.y;
		u.x = s.x + AB.x * (cos60) + AB.y * (-sin60);
		u.y = s.y + AB.x * (sin60) + AB.y * (cos60);
		Recursion(n - 1, p1, s);
		Recursion(n - 1, s, u);
		Recursion(n - 1, u, t);
		Recursion(n - 1, t, p2);
	}
}

int main(void)
{
	int n;
	Point p1, p2;
	p1.x = p1.y = p2.y = 0;
	p2.x = 100;

	while (scanf("%d", &n) != EOF)
	{
		Recursion(n, p1, p2);
		printf("%.8lf %.8lf\n", p2.x, p2.y);
	}

	return 0;
}