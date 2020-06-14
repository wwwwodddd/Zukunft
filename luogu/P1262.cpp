#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int in[100020];
int n, m, x, y, cnt;
int dfn[100020];
int low[100020];
int stk[100020], ss;
int v[100020];
int r[100020], scc;
int w[100020];
int f[100020];
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
void work()
{
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i] && w[i] < 1e9)
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			printf("NO\n");
			printf("%d\n", i);
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j: a[i])
		{
			if (r[i] != r[j])
			{
				in[r[j]]++;
			}
		}
		f[r[i]] = min(f[r[i]], w[i]);
	}
	int ans = 0;
	for (int i = 1; i <= scc; i++)
	{
		if (!in[i])
		{
			ans += f[i];
		}
	}
	printf("YES\n");
	printf("%d\n", ans);
	return;
}
int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	memset(w, 0x3f, sizeof w);
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		w[x] = y;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	work();
	return 0;
}