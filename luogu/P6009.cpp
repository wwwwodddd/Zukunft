#include <bits/stdc++.h>
using namespace std;
int n, m, x;
const int mod = 1000000007;
int p[50020][20][20], q[50020][20][20];
int f[20][20][20];
int g[20][20][20];
void amul(int a[20][20], int b[20][20], int c[20][20])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (a[i][k] == 0)
			{
				continue;
			}
			for (int j = 0; j < m; j++)
			{
				c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % mod;
			}
		}
	}
}
void bmul(int a[20][20], int b[20][20], int c[20][20])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = 0;
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int k = 0; k < m; k++)
		{
			if (b[k][j] == 0)
			{
				continue;
			}
			for (int i = 0; i < m; i++)
			{
				c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % mod;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			f[i][j][j] = 1;
			g[i][j][j] = 1;
		}
		for (int j = 0; j <= i; j++)
		{
			f[i][j][i] += 1;
			g[i][j][i] = (g[i][j][i] + (mod - 1) / 2) % mod;
		}
	}
	for (int i = 0; i < m; i++)
	{
		p[0][i][i] = 1;
		q[0][i][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		x--;
		bmul(p[i - 1], f[x] , p[i]);
		amul(g[x] , q[i - 1], q[i]);
	}
	int t, l, r;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &l, &r);
		l--;
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans = (ans + (long long)q[l][0][i] * p[r][i][j]) % mod;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}