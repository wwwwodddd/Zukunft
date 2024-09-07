#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
struct P
{
	double x, r, x1, y1, x2, y2, k;
} a[1020];
template <typename T>
inline T sqr(T x)
{
	return x * x;
}
int n;
double f(double x)
{
	double re = 0;
	for (int i = 0; i < n; i++)
	{
		if (fabs(a[i].x - x) < a[i].r)
		{
			re = max(re, sqrt(sqr(a[i].r) - sqr(a[i].x - x)));
		}
		if (a[i].x1 < x && x < a[i].x2)
		{
			re = max(re, a[i].k * (x - a[i].x1) + a[i].y1);
		}
	}
	return re;
}
inline double S(double fl, double fr, double fmid, double l, double r)
{
	return (fl + fr + 4 * fmid) * (r - l) / 6;
}
double F(double slr, double fl, double fr, double fmid, double l, double r)
{
	double mid = (l + r) * 0.5;
	double flm = f((l + mid) * 0.5);
	double fmr = f((mid + r) * 0.5);
	double slm = S(fl, fmid, flm, l, mid);
	double smr = S(fmid, fr, fmr, mid, r);
	if (fabs(slr - slm - smr) < eps)
	{
		return slm + smr;
	}
	return F(slm, fl, fmid, flm, l, mid) + F(smr, fmid, fr, fmr, mid, r);
}
int main()
{
	double ag;
	scanf("%d%lf", &n, &ag);
	ag = 1 / tan(ag);
	double h = 0;
	for (int i = 0; i <= n; i++)
	{
		double t;
		scanf("%lf", &t);
		h += t;
		a[i].x = h * ag;
	}
	double le = a[n].x;
	double re = le;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &a[i].r);
		le = min(le, a[i].x - a[i].r);
		re = max(re, a[i].x + a[i].r);
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i + 1].x - a[i].x > fabs(a[i + 1].r - a[i].r))
		{
			a[i].x1 = a[i].x + a[i].r * (a[i].r - a[i + 1].r) / (a[i + 1].x - a[i].x);
			a[i].y1 = sqrt(sqr(a[i].r) - sqr(a[i].x1 - a[i].x));
			a[i].x2 = a[i + 1].x + a[i + 1].r * (a[i].r - a[i + 1].r) / (a[i + 1].x - a[i].x);
			a[i].y2 = sqrt(sqr(a[i + 1].r) - sqr(a[i].x2 - a[i + 1].x));
			a[i].k = (a[i].y2 - a[i].y1) / (a[i].x2 - a[i].x1);
		}
	}
	double fl = f(le);
	double fr = f(re);
	double fmid = f((le + re) * 0.5);
	double slr = S(fl, fr, fmid, le, re);
	printf("%.2f\n", F(slr, fl, fr, fmid, le, re) * 2);
	return 0;
}