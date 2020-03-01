#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m;
vector<pair<int, pair<int, int> > > a[100020];
vector<int> b;
priority_queue<pair<int, int> > q;
int d[100020];
int f[100020];
int g[100020];
int ans[100020];
void dijk(int s)
{
	memset(d, 0x3f, sizeof d);
	memset(f, 0, sizeof 0);
	b.clear();
	d[s] = 0;
	f[s] = 1;
	q.push(make_pair(-d[s], s));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > d[u.second]) {
			continue;
		}
		b.push_back(u.second);
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i].second;
			if (d[e.first] > d[u.second] + e.second) {
				d[e.first] = d[u.second] + e.second;
				f[e.first] = f[u.second];
				q.push(make_pair(-d[e.first], e.first));
			}
			else if (d[e.first] == d[u.second] + e.second)
			{
				f[e.first] = (f[e.first] + f[u.second]) % mod;
			}
		}
	}
	for (int i = b.size() - 1; i >= 0; i--)
	{
		g[b[i]] = 1;
		for (int j = 0; j < a[b[i]].size(); j++)
		{
			int k = a[b[i]][j].first;
			pair<int, int> e = a[b[i]][j].second;
			if (d[e.first] == d[b[i]] + e.second)
			{
				g[b[i]] = (g[b[i]] + g[e.first]) % mod;
				ans[k] = (ans[k] + (long long)f[b[i]] * g[e.first]) % mod;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(i, make_pair(y, z)));
	}
	for (int i = 1; i <= n; i++)
	{
		dijk(i);
	}
	for (int i = 0; i < m; i++)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}