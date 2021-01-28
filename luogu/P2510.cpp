#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
double pi=acos(-1.);
double eps=1e-8;
double r[1020];
double x[1020];
double y[1020];
pair<double, int> a[4020];
int n, ac;
double z;
void add(double st, double ed)
{
	if(st<-pi)
	{
		a[ac++] = make_pair(st+2*pi, +1);
		a[ac++] = make_pair(pi, -1);
		a[ac++] = make_pair(-pi, +1);
	}
	else
	{
		a[ac++] = make_pair(st, +1);
	}
	if(ed>pi)
	{
		a[ac++] = make_pair(pi, -1);
		a[ac++] = make_pair(-pi, +1);
		a[ac++] = make_pair(ed-2*pi, -1);
	}
	else
	{
		a[ac++] = make_pair(ed, -1);
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &r[i], &x[i], &y[i]);
	}
	for (int i = 0, j; i < n; i++)
	{
		ac = 0;
		for (j = i + 1; j < n; j++)
		{
			double d = hypot(x[i] - x[j], y[i] - y[j]);
			if (d + r[i] <= r[j])
			{
				break;
			}
			if (r[i] + r[j] <= d || d + r[j] <= r[i])
			{
				continue;
			}
			double a = atan2(y[j] - y[i], x[j] - x[i]);
			double b = acos((r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i] * d));
			add(a - b, a + b);
		}
		if (j < n)
		{
			continue;
		}
		sort(a, a + ac);
		int c = 0;
		double ag = 0;
		for (int j = 0; j < ac; j++)
		{
			c += a[j].second;
			if (c > 0)
			{
				ag += a[j + 1].first - a[j].first;
			}
		}
		z += (2 * pi - ag) * r[i];
		end:;
	}
	printf("%.3f\n", z);
	return 0;
}