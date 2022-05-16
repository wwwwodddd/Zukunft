#include <bits/stdc++.h>
using namespace std;
int t, n, m, s, e;
vector<pair<int, int> > a[100020];
priority_queue<pair<long long, int> > q;
long long d[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d%d", &n, &m, &s, &e);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			z += 12;
			a[x].push_back(make_pair(y, z));
			a[y].push_back(make_pair(x, z));
		}
		memset(d, 0x3f, sizeof d);
		d[s] = 0;
		q.push(make_pair(-d[s], s));
		while (q.size() > 0)
		{
			pair<int, int> u = q.top();
			q.pop();
			if (-u.first > d[u.second])
			{
				continue;
			}
			for (int i = 0; i < a[u.second].size(); i++)
			{
				pair<int, int> e = a[u.second][i];
				if (d[e.first] > d[u.second] + e.second)
				{
					d[e.first] = d[u.second] + e.second;
					q.push(make_pair(-d[e.first], e.first));
				}
			}
		}
		printf("%lld\n", d[e]);
	}
	return 0;
}