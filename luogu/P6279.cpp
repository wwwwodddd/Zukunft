#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[200020];
int c[200020], cc;
vector<int> a[200020];
set<int> q;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return;
	}
	if (x > y)
	{
		swap(x, y);
	}
	f[y] = x;
	if (a[x].size() < a[y].size())
	{
		a[x].swap(a[y]);
	}
	for (int i: a[y])
	{
		a[x].push_back(F(i));
	}
	a[y].clear();
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		if (a[i].size() > 1)
		{
			q.insert(i);
		}
	}
	while (q.size())
	{
		int u = *q.begin();
		u = F(u);
		q.erase(q.begin());
		for (int i = 0; i < a[u].size(); i++)
		{
			a[u][i] = F(a[u][i]);
		}
		sort(a[u].begin(), a[u].end());
		a[u].resize(unique(a[u].begin(), a[u].end()) - a[u].begin());
		if (a[u].size() > 0)
		{
			int base = a[u][0];
			for (int i = 1; i < a[u].size(); i++)
			{
				U(base, a[u][i]);
			}
			base = F(base);
			if (a[base].size() > 1)
			{
				q.insert(base);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[F(i)] == 0)
		{
			c[F(i)] = ++cc;
		} 
		printf("%d\n", c[F(i)]);
	}
	return 0;
}