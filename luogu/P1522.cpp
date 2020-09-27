#include <bits/stdc++.h>
using namespace std;
int n;
int x[150], y[150];
double d[150][150], f[150];
double l, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			scanf(" %c", &c);
			if (c == '1' || i == j)
			{
				d[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
			}
			else
			{
				d[i][j] = 1e30;
			}
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] < 1e9)
			{
				f[i] = max(f[i], d[i][j]);
			}
		}
		l = max(l, f[i]);
	}
	z = 1e30;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] > 1e9)
			{
				z = min(z, f[i] + hypot(x[i] - x[j], y[i] - y[j]) + f[j]);
			}
		}
	}
	printf("%.6f\n", max(l, z));
	return 0;
}