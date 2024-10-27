#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m;
int f[520][520];
int g[520];
int main()
{
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	for (int i = 0; i < m; i++)
	{
		f[i + 1][1] = f[i][0];
		for (int j = 1; j <= i; j++)
		{
			f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % p;
			f[i + 1][j - 1] = (f[i + 1][j - 1] + f[i][j]) % p;
		}
	}
	g[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = m; j >= 0; j--)
		{
			g[j] = (long long)g[j] * f[m][0] % p;
			for (int k = 1; k <= j; k++)
			{
				g[j] = (g[j] + (long long)g[j - k] * f[m][k]) % p;
			}
		}
	}
	long long z = 0;
	for (int i = 0; i <= m; i++)
	{
		z = (z + (long long)g[i] * f[m][i]) % p;
	}
	printf("%lld\n", z);
	return 0;
}