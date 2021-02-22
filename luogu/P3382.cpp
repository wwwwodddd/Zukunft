#include <bits/stdc++.h>
int n;
double a[20];
double F(double x)
{
	double r = 0;
	for (int i = n; i > 0; i--)
	{
		r = r * x + a[i] * i;
	}
	return r;
}
int main()
{
	double L, R;
	scanf("%d%lf%lf", &n, &L, &R);
	for (int i = n; i >= 0; i--)
	{
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i < 99; i++)
	{
		double M = (L + R) / 2;
		if (F(M) > 0)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	printf("%.5f\n", (L + R) / 2);
	return 0;
}