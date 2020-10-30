#include <bits/stdc++.h>
using namespace std;
int main()
{
	double p, q, r;
	scanf("%lf%lf%lf", &p, &q, &r);
	q = min(q, p - q);
	double pi = acos(-1.0);
	double a = pi / p;
	double b = ((0.5 - q / p) * pi);
	double s = p * r * r * sin(a) * sin(b) / sin(a + b);
	printf("%.5f\n", s);
	return 0;
}