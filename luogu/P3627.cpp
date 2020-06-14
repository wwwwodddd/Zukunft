#include <bits/stdc++.h>
using namespace std;
vector<int> a[500020];
vector<int> b[500020];
int n, m, x, y, cnt;
int dfn[500020];
int low[500020];
int stk[500020], ss;
int f[500020];
int v[500020];
int r[500020], scc;
int w[500020];
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
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j: a[i])
		{
			if (r[i] != r[j])
			{
				b[r[i]].push_back(r[j]);
			}
		}
		scanf("%d", &y);
		w[r[i]] += y;
	}
	int start, q;
	scanf("%d%d", &start, &q);
	memset(f, 0xc0, sizeof f);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &x);
		f[r[x]] = 0;
	}
	for (int i = 1; i <= scc; i++)
	{
		for (int j: b[i])
		{
			f[i] = max(f[i], f[j]);
		}
		f[i] += w[i];
	}
	printf("%d\n", f[r[start]]);
	return 0;
}