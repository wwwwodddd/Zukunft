#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int c[100020];
int f[100020][22];
int g[22];
void inc(int f[22])
{
	rotate(f, f + m, f + m + 1);
	f[0] = 0;
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
				f[x][j] += f[i][j];
			}
		}
	}
	inc(f[x]);
	f[x][0] += c[x];
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
				g[j] = f[x][j] - g[j];
			}
			inc(g);
			for (int j = 0; j <= m; j++)
			{
				f[i][j] += g[j];
			}
			dfs2(i, x);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	{
		int r = 0;
		for (int j = 0; j <= m; j++)
		{
			r += f[i][j];
		}
		printf("%d\n", r);
	}
	return 0;
}