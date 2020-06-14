#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
vector<int> b[100020];
int n, m, x, y, cnt;
int dfn[100020];
int low[100020];
int stk[100020], ss;
int sum[100020];
int f[100020];
int v[100020];
int r[100020], scc;
int w[100020];
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
			sum[scc] += w[u];
		}
		while (u != x);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
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
	}
	int ans = 0;
	for (int i = 1; i <= scc; i++)
	{
		for (int j: b[i])
		{
			f[i] = max(f[i], f[j]);
		}
		f[i] += sum[i];
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}