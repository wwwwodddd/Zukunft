#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
vector<int> b[100020];
int n, m, mod, x, y, cnt;
int dfn[100020];
int low[100020];
int stk[100020], ss;
int c[100020];
int f[100020];
int g[100020];
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
	scanf("%d%d%d", &n, &m, &mod);
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
		c[r[i]]++;
	}
	int ansf = 0, ansg = 1;
	for (int i = 1; i <= scc; i++)
	{
		g[i] = 1;
		sort(b[i].begin(), b[i].end());
		b[i].resize(unique(b[i].begin(), b[i].end()) - b[i].begin());
		for (int j: b[i])
		{
			if (f[i] < f[j])
			{
				f[i] = f[j];
				g[i] = g[j];
			}
			else if (f[i] == f[j])
			{
				g[i] = (g[i] + g[j]) % mod;
			}
		}
		f[i] += c[i];
		if (ansf < f[i])
		{
			ansf = f[i];
			ansg = g[i];
		}
		else if (ansf == f[i])
		{
			ansg = (ansg + g[i]) % mod;
		}
	}
	printf("%d\n", ansf);
	printf("%d\n", ansg);
	return 0;
}