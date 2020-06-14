#include <bits/stdc++.h>
using namespace std;
vector<int> a[200020];
vector<pair<int, int> > b[200020];
int n, m, cnt;
int dfn[200020];
int low[200020];
int stk[200020], ss;
int sum[200020];
int f[200020];
int v[200020];
int r[200020], scc;
int x[1000020];
int y[1000020];
int w[1000020];
void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	stk[ss++] = x;
	v[x] = 1;
	for (int y: a[x])
	{
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (v[y])
		{
			low[x] = min(low[x], dfn[y]);
		}
	}
	if (dfn[x] == low[x])
	{
		scc++;
		int u;
		do
		{
			u = stk[--ss];
			r[u] = scc;
			v[u] = 0;
		}
		while (u != x);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		a[x[i]].push_back(y[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (r[x[i]] != r[y[i]])
		{
			b[r[x[i]]].push_back(make_pair(r[y[i]], w[i]));
		}
	}
	memset(f, 0x3f, sizeof f);
	f[r[n]] = 0;
	for (int i = 1; i <= scc; i++)
	{
		for (pair<int, int> j: b[i])
		{
			f[i] = min(f[i], f[j.first] + j.second);
		}
	}
	printf("%d\n", f[r[1]]);
	return 0;
}