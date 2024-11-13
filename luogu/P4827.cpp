#include <bits/stdc++.h>
using namespace std;
const int p = 10007;
int t, n, m;
vector<int> a[50020];
int fac[152];
int c[152][152];
int s[152][152];
int f[50020][152];
int g[152];
void inc(int f[152])
{
	for (int i = m; i > 0; i--)
	{
		f[i] = (f[i] + f[i - 1]) % p;
	}
}
void dfs1(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs1(i, x);
			for (int j = 0; j <= m; j++)
			{
				f[x][j] = (f[x][j] + f[i][j]) % p;
			}
		}
	}
	inc(f[x]);
	f[x][0]++;
}
void dfs2(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			memcpy(g, f[i], sizeof g);
			inc(g);
			for (int j = 0; j <= m; j++)
			{
				g[j] = (f[x][j] + p - g[j]) % p;
			}
			inc(g);
			for (int j = 0; j <= m; j++)
			{
				f[i][j] = (f[i][j] + g[j]) % p;
			}
			dfs2(i, x);
		}
	}
}
int main()
{
	fac[0] = 1;
	for (int i = 1; i < 152; i++)
	{
		fac[i] = fac[i - 1] * i % p;
	}
	s[0][0] = 1;
	for (int i = 0; i < 152; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
			s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % p;
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	{
		int r = 0;
		for (int j = 1; j <= m; j++)
		{
			r = (r + f[i][j] * s[m][j] % p * fac[j]) % p;
		}
		printf("%d\n", r);
	}
	return 0;
}