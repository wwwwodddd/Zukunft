#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<pair<int, int>, pair<int, int> > b[1020];
vector<pair<int, int> > a[1020];
priority_queue<pair<int, int> > q;
int d[100020];
int dijk()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.push(make_pair(-d[1], 1));
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
	return d[n];
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i].second.first >> b[i].second.second >> b[i].first.second >> b[i].first.first;
	}
	sort(b, b + m);
	long long ans = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		a[b[i].second.first].push_back(make_pair(b[i].second.second, b[i].first.second));
		a[b[i].second.second].push_back(make_pair(b[i].second.first, b[i].first.second));
		ans = max(ans, 1000000LL * b[i].first.first / dijk());
	}
	cout << ans << endl;
	return 0;
}