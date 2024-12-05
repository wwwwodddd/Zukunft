#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<pair<int, int>> a[100020];
set<pair<long long, int>> q;
long long d[100020];
int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	q.insert(make_pair(d[s], s));
	while (q.size() > 0)
	{
		pair<long long, int> u = *q.begin();
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
	printf("%lld\n", d[t]);
	return 0;
}