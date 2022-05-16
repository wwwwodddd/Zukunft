#include <bits/stdc++.h>
using namespace std;
int n, m, l;
vector<int> a[500020];
int f[500020][20];
int d[500020];
int h[500020];
int v[1000020];
void dfs(int x, int y)
{
	f[x][0] = y;
	d[x] = d[y] + 1;
	h[x] += h[y];
	for (int i = 1; i < 20; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int lca(int x, int y)
{
	if (d[x] < d[y])
	{
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++)
	{
		if (dd >> i & 1)
		{
			x = f[x][i];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main()
{
	for (int i = 2; i < 1000010; i++)
	{
		if (!v[i])
		{
			for (int j = i; j < 1000010; j += i)
			{
				v[j]++;
			}
		}
	}
	scanf("%d%d%d", &n, &l, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
		h[i] = (v[h[i]] >= l);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int z = lca(x, y);
		printf("%d\n", h[x] + h[y] - h[z] - h[f[z][0]]);
	}
	return 0;
}