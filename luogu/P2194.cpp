#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
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
int g[100020];
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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	scanf("%d", &m);
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
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		if (f[r[i]] > w[i])
		{
			f[r[i]] = w[i];
			g[r[i]] = 1;
		}
		else if (f[r[i]] == w[i])
		{
			g[r[i]]++;
		}
	}
	long long ans1 = 0, ans2 = 1;
	for (int i = 1; i <= scc; i++)
	{
		ans1 += f[i];
		ans2 = ans2 * g[i] % mod;
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}