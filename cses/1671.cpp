#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[100020];
set<pair<long long, int> > q;
long long d[100020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.insert(make_pair(d[1], 1));
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
	for (int i = 1; i <= n; i++)
	{
		printf("%lld%c", d[i], i == n ? '\n' : ' ');
	}
	return 0;
}