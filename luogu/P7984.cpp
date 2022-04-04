#include <bits/stdc++.h>
using namespace std;
int n, m, N;
vector<pair<int, int> > a[362145];
long long d1[362145];
long long d2[362145];
long long d3[362145];
set<pair<long long, int> > s;
void dijk(long long *d)
{
	while (s.size())
	{
		int u = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < a[u].size(); i++)
		{
			if (d[a[u][i].first] > d[u] + a[u][i].second)
			{
				s.erase(make_pair(d[a[u][i].first], a[u][i].first));
				d[a[u][i].first] = d[u] + a[u][i].second;
				s.insert(make_pair(d[a[u][i].first], a[u][i].first));
			}
		}
	}
}
void jia(int t, int l, int r, int x, int y, int i)
{
	if (r <= x || y <= l)
	{
		return;
	}
	if (x <= l && r <= y)
	{
		a[t].push_back(make_pair(2 * N + i, 0));
		return;
	}
	jia(t * 2, l, (l + r) / 2, x, y, i);
	jia(t * 2 + 1, (l + r) / 2, r, x, y, i);
}
int main()
{
	scanf("%d%d", &n, &m);
	N = 1;
	while (N <= n)
	{
		N *= 2;
	}
	for (int i = 2; i <= 2 * N; i++)
	{
		a[i].push_back(make_pair(i / 2, 0));
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, c, p;
		scanf("%d%d%d%d", &c, &p, &x, &y);
		jia(1, 0, N, x, y + 1, i);
		a[2 * N + i].push_back(make_pair(N + c, p));
	}
	memset(d1, 0x3f, sizeof d1);
	d1[N + 1] = 0;
	s.insert(make_pair(0, N + 1));
	dijk(d1);

	memset(d2, 0x3f, sizeof d2);
	d2[N + n] = 0;
	s.insert(make_pair(0, N + n));
	dijk(d2);

	memset(d3, 0x3f, sizeof d3);
	for (int i = 1; i <= 2 * N + m; i++)
	{
		d3[i] = min(d3[i], d1[i] + d2[i]);
		s.insert(make_pair(d3[i], i));
		// cout << i << " " << d1[i] << " " << d2[i] << " " << d3[i] << endl;
	}
	dijk(d3);
	for (int i = 1; i <= n; i++)
	{
		if (d3[N + i] > 1e18)
		{
			d3[N + i] = -1;
		}
		printf("%lld\n", d3[N + i]);
	}
	return 0;
}