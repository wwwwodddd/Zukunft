#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, q, bs, s, bt, t;
int f[62][62][62];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &f[i][j][1]);
		}
	}
	for (int k = 2; k <= m; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				f[i][j][k] = f[i][j][k - 1];
				for (int t = 1; t <= n; t++)
				{
					f[i][j][k] = (f[i][j][k] + (long long)f[i][t][k - 1] * f[t][j][k - 1]) % mod;
				}
			}
		}
	}
	for (int qq = 0; qq < q; qq++)
	{
		scanf("%d%d%d%d", &bs, &s, &bt, &t);
		long long g[62][62] = {}, h[62][62] = {};
		g[s][bs] = h[t][bt] = 1;
		g[s][bs + 1] = h[t][bt + 1] = -1;
		int z = 0;
		for (int l = 1; l <= m; l++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[j][l] = (g[j][l] + g[j][l - 1]) % mod;
				h[j][l] = (h[j][l] + h[j][l - 1]) % mod;
				for (int i = 1; i <= n; i++)
				{
					g[j][l] = (g[j][l] + g[i][l - 1] * f[i][j][l - 1]) % mod;
					h[j][l] = (h[j][l] + h[i][l - 1] * f[j][i][l - 1]) % mod;
				}
				z = (z + g[j][l] * h[j][l]) % mod;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}