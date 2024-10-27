#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y, z;
long long d[1020][1020];
int s[1020];
vector<pair<int, int> > a[1020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z;
			a[x].push_back(make_pair(y, z));
			a[y].push_back(make_pair(x, z));
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &s[i]);
		}
		memset(d, 0x3f, sizeof d);
		d[1][s[1]] = 0;
		priority_queue<pair<long long, pair<int, int> > > q;
		q.push(make_pair(0, make_pair(1, s[1])));
		while (q.size() > 0)
		{
			auto u = q.top().second;
			long long dd = q.top().first;
			q.pop();
			if (u.first == n)
			{
				cout << -dd << endl;
				break;
			}
			if (-dd > d[u.first][u.second])
			{
				continue;
			}
			for (auto i : a[u.first])
			{
				int ns = min(u.second, s[i.first]);
				if (d[i.first][ns] > d[u.first][u.second] + u.second * i.second)
				{
					d[i.first][ns] = d[u.first][u.second] + u.second * i.second;
					q.push(make_pair(-d[i.first][ns], make_pair(i.first, ns)));
				}
			}
		}
	}
	return 0;
}