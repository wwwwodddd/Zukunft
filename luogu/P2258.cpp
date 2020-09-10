#include <bits/stdc++.h>
using namespace std;
int n, m, r, c;
int a[20][20];
int b[20];
int rs[20];
int cs[20][20];
int f[20][20];
int main()
{
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int z = 1e9;
	for (int u = 0; u < 1 << n; u++)
	{
		if (__builtin_popcount(u) != r)
		{
			continue;
		}
		int t = 0;
		for (int i = 0; i < n; i++)
		{
			if (u >> i & 1)
			{
				b[t++] = i;
			}
		}
		for (int j = 0; j < m; j++)
		{
			rs[j] = 0;
			for (int i = 1; i < r; i++)
			{
				rs[j] += abs(a[b[i-1]][j] - a[b[i]][j]);
			}
		}
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < j; k++)
			{
				cs[j][k] = 0;
				for (int i = 0; i < r; i++)
				{
					cs[j][k] += abs(a[b[i]][j] - a[b[i]][k]);
				}
			}
		}
		memset(f, 0x3f, sizeof f);
		for (int j = 0; j < m; j++)
		{
			f[1][j] = rs[j];
		}
		for (int j = 0; j < m; j++)
		{
			for (int i = 2; i <= c; i++)
			{
				for (int k = 0; k < j; k++)
				{
					f[i][j] = min(f[i][j], f[i-1][k] + rs[j] + cs[j][k]);
				}
			}
			z = min(z, f[c][j]);
		}
	}
	printf("%d\n", z);
	return 0;
}