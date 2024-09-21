#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[250020];
int d[250020];
int s, t, n;
set<pair<int, int> > q;
void add(int x, int y, int z)
{
	a[x].push_back(make_pair(y, z));
}
int cg(int x, int y)
{
	if (x < 0 || y >= n)
	{
		return t;
	}
	else if (y < 0 || x >= n)
	{
		return s;
	}
	else
	{
		return x * n + y;
	}
}
int main()
{
	int i, j, w;
	scanf("%d", &n);
	s = n * n;
	t = s + 1;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &w);
			add(cg(i, j), cg(i - 1, j), w);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			scanf("%d", &w);
			add(cg(i, j - 1), cg(i, j), w);
		}
	}
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &w);
			add(cg(i - 1, j), cg(i, j), w);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			scanf("%d", &w);
			add(cg(i, j), cg(i, j - 1), w);
		}
	}
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	q.insert(make_pair(d[s], s));
	while (q.size() > 0)
	{
		pair<int, int> u = *q.begin();
		q.erase(q.begin());
		for (int i = 0; i < a[u.second].size(); i++)
		{
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > d[u.second] + e.second)
			{
				q.erase(make_pair(d[e.first], e.first));
				d[e.first] = d[u.second] + e.second;
				q.insert(make_pair(d[e.first], e.first));
			}
		}
	}
	printf("%d\n", d[t]);
	return 0;
}