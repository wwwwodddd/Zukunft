#include <bits/stdc++.h>
using namespace std;
double s[10020];
double k[10020];
double v[10020];
double e, t;
int n;
double sov(double c, double d)
{
	double l = c, r = 1e10;
	for (int _ = 0; _ < 100; _++)
	{
		double m = (l + r) / 2;
		if (m * m * (m - c) > d)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return l;
}
bool ok(double c)
{
	double E = e;
	t = 0;
	for (int i = 0; i < n; i++)
	{
		double spd = sov(v[i], c / k[i]);
		E -= k[i] * (spd - v[i]) * (spd - v[i]) * s[i];
		t += s[i] / spd;
		if (E < 0)
		{
			return false;
		}
	}
	return E >= 0;
}
int main()
{
	scanf("%d%lf", &n, &e);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &s[i], &k[i], &v[i]);
	}
	double l = 0, r = 1e10;
	for (int _ = 0; _ < 100; _++)
	{
		double m = (l + r) / 2;
		if (ok(m))
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	ok(l);
	printf("%.6f\n", t);
	return 0;
}