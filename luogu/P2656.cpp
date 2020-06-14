#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
vector<pair<int, int> > b[100020];
int n, m, cnt;
int dfn[100020];
int low[100020];
int stk[100020], ss;
int sum[100020];
int f[100020];
int v[100020];
int r[100020], scc;
int x[200020];
int y[200020];
int w[200020];
double z[200020];
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
		scanf("%d%d%d%lf", &x[i], &y[i], &w[i], &z[i]);
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
		else
		{
			int t = w[i];
			while (t > 0)
			{
				sum[r[x[i]]] += t;
				t *= z[i];
			}
		}
	}
	for (int i = 1; i <= scc; i++)
	{
		for (pair<int, int> j: b[i])
		{
			f[i] = max(f[i], f[j.first] + j.second);
		}
		f[i] += sum[i];
	}
	int start;
	scanf("%d", &start);
	printf("%d\n", f[r[start]]);
	return 0;
}