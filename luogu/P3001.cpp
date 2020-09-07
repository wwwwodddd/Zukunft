#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int x[25020];
int y[25020];
long double z[25020];
long double d[2020], v;
int main()
{
	scanf("%d%d%Lf%d%d", &n, &m, &v, &a, &b);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%Lf", &x[i], &y[i], &z[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1e30;
	}
	d[a] = v;
	bool changed;
	for (int i = 0; i < n; i++)
	{
		changed = false;
		for (int i = 0; i < m; i++)
		{
			if (d[y[i]] > d[x[i]] * z[i])
			{
				d[y[i]] = d[x[i]] * z[i];
				changed = true;
			}
		}
		if (!changed)
		{
			break;
		}
	}
	if (changed)
	{
		printf("0\n");
	}
	else
	{
		printf("%.6Lf\n", d[b]);
	}
	return 0;
}