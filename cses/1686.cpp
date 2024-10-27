#include <bits/stdc++.h>
using namespace std;
vector<int> a[500020];
vector<int> b[500020];
int n, m, x, y, cnt;
int dfn[500020];
int low[500020];
int stk[500020], ss;
long long f[500020];
int v[500020];
int r[500020], scc;
long long w[500020];
int k[500020];
void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	stk[ss++] = x;
	v[x] = 1;
	for (int y : a[x])
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
		} while (u != x);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
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
		for (int j : a[i])
		{
			if (r[i] != r[j])
			{
				b[r[i]].push_back(r[j]);
			}
		}
		w[r[i]] += k[i];
	}
	long long z = 0;
	for (int i = 1; i <= scc; i++)
	{
		for (int j : b[i])
		{
			f[i] = max(f[i], f[j]);
		}
		f[i] += w[i];
		z = max(z, f[i]);
	}
	printf("%lld\n", z);
	return 0;
}