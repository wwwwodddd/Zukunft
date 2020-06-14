#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int c[100020];
int n, m, x, y, z, cnt;
int dfn[100020];
int low[100020];
int stk[100020], ss;
int v[100020];
int r[100020], scc;
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
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(y);
		if (z == 2)
		{
			a[y].push_back(x);
		}
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
		c[r[i]]++;
	}
	int ans = 0, ansr;
	for (int i = 1; i <= n; i++)
	{
		if (ans < c[r[i]])
		{
			ans = c[r[i]];
			ansr = r[i];
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		if (r[i] == ansr)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}