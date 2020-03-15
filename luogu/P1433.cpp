#include <bits/stdc++.h>
using namespace std;
int n;
double x[16];
double y[16];
double f[65536][16];
double z = 1e30;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	n++;
	memset(f, 0x7f, sizeof f);
	f[1][0] = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (~i >> k & 1)
					{
						f[i | 1 << k][k] = min(f[i | 1 << k][k], f[i][j] + hypot(x[j] - x[k], y[j] - y[k]));
					}
				}
			}
			if (i == (1 << n) - 1)
			{
				z = min(z, f[i][j]);
			}
		}
	}
	printf("%.2f\n", z);
	return 0;
}