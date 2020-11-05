#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[1520][1520];
int f[1520][1520];
int g[1520][1520];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			if (i + j & 1)
			{
				a[i][j] ^= 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j])
			{
				f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
				z = max(z, f[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!a[i][j])
			{
				g[i][j] = min(g[i - 1][j - 1], min(g[i - 1][j], g[i][j - 1])) + 1;
				z = max(z, g[i][j]);
			}
		}
	}
	printf("%d\n", z);
	return 0;
}