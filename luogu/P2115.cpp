#include <bits/stdc++.h>
using namespace std;
int n;
double a[100020], s;
bool ok(double M)
{
	double f = 0, z = -M;
	for (int i = 2; i < n; i++)
	{
		f = max(f, 0.) + a[i] - M;
		z = max(z, f);
	}
	return s - n * M < z;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
		s += a[i];
	}
	double L = 0;
	double R = 10000;
	for (int i = 0; i < 100; i++)
	{
		double M = (L + R) / 2;
		if (ok(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%.3f\n", L);
	return 0;
}