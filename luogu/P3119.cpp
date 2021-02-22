#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
vector<int> b[100020];
int n, m, x, y;
int dfn[100020];
int low[100020];
int s[100020], ss;
int r[100020];
int c[100020];
int f[100020];
int g[100020];
int cnt, scc;
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	s[ss++] = x;
	for (int i: a[x])
	{
		if (!dfn[i])
		{
			dfs(i);
			low[x] = min(low[x], low[i]);
		}
		else if (!r[i])
		{
			low[x] = min(low[x], dfn[i]);
		}
	}
	if (dfn[x] == low[x])
	{
		scc++;
		while (s[ss] != x)
		{
			r[s[--ss]] = scc;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		c[r[i]]++;
		for (int j: a[i])
		{
			if (r[i] != r[j])
			{
				b[r[i]].push_back(r[j]);
			}
		}
	}
	memset(f, 0xc0, sizeof f);
	memset(g, 0xc0, sizeof f);
	f[r[1]] = 0;
	g[r[1]] = 0;
	for (int i = scc; i > 0; i--)
	{
		for (int j: b[i])
		{
			f[j] = max(f[j], f[i] + c[j]);
		}
	}
	for (int i = 1; i <= scc; i++)
	{
		for (int j: b[i])
		{
			g[i] = max(g[i], g[j] + c[i]);
		}
	}
	int z = 0;
	for (int i = 1; i <= scc; i++)
	{
		for (int j: b[i])
		{
			z = max(z, c[r[1]] + f[j] + g[i]);
		}
	}
	printf("%d\n", z);
	return 0;
}