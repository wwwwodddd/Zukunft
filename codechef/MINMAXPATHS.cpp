#include <bits/stdc++.h>
using namespace std;
int t, n, m, s;
vector<int> a[200020];
int f[200020][20];
int g[200020][20]; // min
int h[200020][20]; // max
int d[200020];
long long z[200020];
void dfs(int x, int y)
{
	f[x][0] = y;
	g[x][0] = y;
	h[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
		g[x][i] = min(g[x][i - 1], g[f[x][i - 1]][i - 1]);
		h[x][i] = max(h[x][i - 1], h[f[x][i - 1]][i - 1]);
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
long long dist(int x, int y)
{
	if (x == y)
	{
		return 0;
	}
	if (d[x] < d[y])
	{
		swap(x, y);
	}
	int dd = d[x] - d[y];
	int mn = min(x, y), mx = max(x, y);
	for (int i = 0; i < 20; i++)
	{
		if (dd >> i & 1)
		{
			mn = min(mn, g[x][i]);
			mx = max(mx, h[x][i]);
			x = f[x][i];
		}
	}
	if (x == y)
	{
		return (long long)mn * mx;
	}
	for (int i = 20 - 1; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			mn = min(mn, g[x][i]);
			mx = max(mx, h[x][i]);
			x = f[x][i];
			mn = min(mn, g[y][i]);
			mx = max(mx, h[y][i]);
			y = f[y][i];
		}
	}
	mn = min(mn, g[x][0]);
	mx = max(mx, h[x][0]);
	return (long long)mn * mx;
	// return f[x][0];
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &s);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			memset(f[i], 0, sizeof f[i]);
			memset(g[i], 0, sizeof g[i]);
			memset(h[i], 0, sizeof h[i]);
		}
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(s, 0);
		for (int i = 1; i <= n; i++)
		{
			if (i == s)
			{
				z[i] = 0;
			}
			else
			{
				z[i] = dist(s, i);
				for (int p = 1; p * (i + s) <= z[i]; p++)
				{
					z[i] = min(z[i], dist(s, p) + dist(p, i));
				}
			}
			printf("%lld ", z[i]);
		}
		printf("\n");
	}
	return 0;
}