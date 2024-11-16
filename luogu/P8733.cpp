#include <bits/stdc++.h>
using namespace std;
int n;
double l;
double x[21], y[21];
double d[21][21];
double f[1048577][21];
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	memset(d, 0x7f, sizeof d);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double h = hypot(x[i] - x[j], y[i] - y[j]);
			if (h <= l)
			{
				d[i][j] = h;
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
	memset(f, 0x7f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		f[1 << i][i] = d[0][i];
	}
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i >> j & 1) && f[i][j] < 1e9)
			{
				for (int k = 0; k < n; k++)
				{
					if (~i >> k & 1)
					{
						f[i | 1 << k][k] = min(f[i | 1 << k][k], f[i][j] + d[j][k]);
					}
				}
			}
		}
	}
	cout << fixed << setprecision(2) << f[(1 << n) - 1][0] << endl;
	return 0;
}