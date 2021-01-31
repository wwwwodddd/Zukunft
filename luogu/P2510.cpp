#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1.);
double r[1020];
double x[1020];
double y[1020];
pair<double, int> a[4020];
int n;
double z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &r[i], &x[i], &y[i]);
	}
	for (int i = 0, j; i < n; i++)
	{
		int c = 0;
		a[c++] = make_pair(-pi, 0);
		a[c++] = make_pair(pi, 0);
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
			double u = atan2(y[j] - y[i], x[j] - x[i]);
			double v = acos((r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i] * d));
			if (u - v < -pi)
			{
				a[c++] = make_pair(u - v + 2 * pi, +1);
				a[c++] = make_pair(pi, -1);
				a[c++] = make_pair(-pi, +1);
			}
			else
			{
				a[c++] = make_pair(u - v, +1);
			}
			if (u + v > pi)
			{
				a[c++] = make_pair(pi, -1);
				a[c++] = make_pair(-pi, +1);
				a[c++] = make_pair(u + v - 2 * pi, -1);
			}
			else
			{
				a[c++] = make_pair(u + v, -1);
			}
		}
		if (j < n)
		{
			continue;
		}
		sort(a, a + c);
		double s = 0;
		for (int j = 0, cnt = 0; j + 1 < c; j++)
		{
			cnt += a[j].second;
			if (cnt == 0)
			{
				s += a[j + 1].first - a[j].first;
			}
		}
		z += s * r[i];
	}
	printf("%.3f\n", z);
	return 0;
}