#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	double x;
	double y;
} Point;

void Symmetric(Point p, Point p1, Point p2)
{
	Point D,AB,AC,BD,x;
	AB.x = p.x - p1.x;
	AB.y = p.y - p1.y;
	AC.x = p2.x - p1.x;
	AC.y = p2.y - p1.y;
	D.x = p1.x + (AB.x * AC.x + AB.y * AC.y) / (AC.x * AC.x + AC.y * AC.y) * AC.x;
	D.y = p1.y + (AB.x * AC.x + AB.y * AC.y) / (AC.x * AC.x + AC.y * AC.y) * AC.y;
	BD.x = D.x - p.x;
	BD.y = D.y - p.y;
	x.x = p.x + 2 * BD.x;
	x.y = p.y + 2 * BD.y;
	printf("%.10lf %.10lf\n", x.x, x.y);
}

int main(void)
{
	Point p1, p2;
	while (scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y) != EOF)
	{
		int q;
		scanf("%d", &q);
		while (q-- != 0)
		{
			Point p;
			scanf("%lf%lf", &p.x, &p.y);
			Symmetric(p, p1, p2);
		}
	}


	return 0;
}