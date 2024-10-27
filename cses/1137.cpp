#include <bits/stdc++.h>
using namespace std;
int n, m, ss, x, y;
vector<int> a[200020];
int l[200020];
int r[200020];
int b[200020];
long long c[200020];
int z[200020];
void dfs(int x, int y)
{
	l[x] = ss;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
	r[x] = ++ss;
}
void change(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
long long query(int x)
{
	long long re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		change(r[i], b[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d", &x, &y);
			change(r[x], y - b[x]);
			b[x] = y;
		}
		else
		{
			scanf("%d", &x);
			printf("%lld\n", query(r[x]) - query(l[x]));
		}
	}
	return 0;
}