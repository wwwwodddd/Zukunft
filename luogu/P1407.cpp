#include <bits/stdc++.h>
using namespace std;
map<string, int> g;
vector<int> a[4020];
string x, y;
int n, m;
int dfn[4020];
int low[4020];
int s[4020], ss;
int v[4020];
int r[4020];
int c[4020];
int cnt, scc;
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	s[ss++] = x;
	v[x] = 1;
	for (int i : a[x])
	{
		if (!dfn[i])
		{
			dfs(i);
			low[x] = min(low[x], low[i]);
		}
		else if (v[i])
		{
			low[x] = min(low[x], dfn[i]);
		}
	}
	if (dfn[x] == low[x])
	{
		int u;
		scc++;
		do
		{
			u = s[--ss];
			v[u] = 0;
			r[u] = scc;
		} while (u != x);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		g[x] = g[y] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[g[x]].push_back(g[y]);
	}
	for (int i = 0; i < n; i++)
	{
		if (!dfn[i])
		{
			dfs(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		c[r[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		puts(c[r[i]] > 1 ? "Unsafe" : "Safe");
	}
	return 0;
}