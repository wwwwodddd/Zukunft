#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x1, y1, x2, y2, x3, y3;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%.2f\n", hypot(x1 - x2, y1 - y2) + hypot(x1 - x3, y1 - y3) + hypot(x2 - x3, y2 - y3));
	return 0;
}