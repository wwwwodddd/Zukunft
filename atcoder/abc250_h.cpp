#include <bits/stdc++.h>
using namespace std;
int n, m, l, q, x, y, z;
long long t;
vector<pair<int, int> > a[200020];
vector<pair<long long, pair<int, int> > > e;
long long d[200020];
int f[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x1f, sizeof d);
	set<pair<long long, int> > s;
	for (int i = 1; i <= l; i++)
	{
		d[i] = 0;
		f[i] = i;
		s.insert(make_pair(d[i], i));
	}
	while (s.size())
	{
		pair<int, int> u = *s.begin();
		s.erase(s.begin());
		for (auto i : a[u.second])
		{
			if (d[i.first] > d[u.second] + i.second)
			{
				s.erase(make_pair(d[i.first], i.first));
				d[i.first] = d[u.second] + i.second;
				f[i.first] = f[u.second];
				s.insert(make_pair(d[i.first], i.first));
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto j: a[i])
		{
			if (f[i] < f[j.first])
			{
				e.push_back(make_pair(j.second + d[i] + d[j.first], make_pair(i, j.first)));
			}
		}
	}
	sort(e.begin(), e.end());
	scanf("%d", &q);
	for (int i = 0, j = 0; i < q; i++)
	{
		scanf("%d%d%lld", &x, &y, &t);
		for (; j < e.size() && e[j].first <= t; j++)
		{
			f[F(e[j].second.first)] = F(e[j].second.second);
		}
		puts(F(x) == F(y) ? "Yes" : "No");
	}
	return 0;
}