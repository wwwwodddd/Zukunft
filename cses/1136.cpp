#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200020];
int f[200020][19];
int d[200020];
int s[200020];
int ans;
void dfs(int x, int y)
{
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 19; i++)
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
void dfs2(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs2(i, x);
			s[x] += s[i];
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
	for (int i = 0; i < 19; i++)
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
	for (int i = 19 - 1; i >= 0; i--)
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
	scanf("%d%d", &n, &m);
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
		int l = lca(x, y);
		s[x]++;
		s[y]++;
		s[l]--;
		s[f[l][0]]--;
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", s[i]);
	}
	return 0;
}