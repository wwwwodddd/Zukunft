#include <bits/stdc++.h>
using namespace std;
long long d[600020];
vector<pair<int, int> > a[600020];
set<pair<long long, int> > q;
int n, m, l, x, y;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &l);
		for (int j = 0; j < l; j++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(make_pair(n + i, y));
			a[n + i].push_back(make_pair(x, y));
		}
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.insert(make_pair(d[1], 1));
	while (q.size() > 0)
	{
		int u = q.begin()->second;
		q.erase(q.begin());
		for (pair<int, int> e: a[u])
		{
			if (d[e.first] > d[u] + e.second)
			{
				q.erase(make_pair(d[e.first], e.first));
				d[e.first] = d[u] + e.second;
				q.insert(make_pair(d[e.first], e.first));
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld%c", d[i], i == n ? '\n' : ' ');
	}
	return 0;
}
