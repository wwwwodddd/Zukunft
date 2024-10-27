#include <bits/stdc++.h>
using namespace std;
const int p = 1234567891;
vector<pair<int, int> > a[100020];
vector<pair<int, int> > b[100020];
int n, m;
long long d1[100020];
long long f1[100020];
long long d2[100020];
long long f2[100020];
set<pair<long long, int> > s;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		b[y].push_back(make_pair(x, z));
	}
	memset(d1, 0x3f, sizeof d1);
	memset(d2, 0x3f, sizeof d2);
	d1[1] = 0;
	f1[1] = 1;
	s.insert(make_pair(0, 1));
	while (s.size())
	{
		int u = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < a[u].size(); i++)
		{
			if (d1[a[u][i].first] > d1[u] + a[u][i].second)
			{
				f1[a[u][i].first] = f1[u];
				s.erase(make_pair(d1[a[u][i].first], a[u][i].first));
				d1[a[u][i].first] = d1[u] + a[u][i].second;
				s.insert(make_pair(d1[a[u][i].first], a[u][i].first));
			}
			else if (d1[a[u][i].first] == d1[u] + a[u][i].second)
			{
				f1[a[u][i].first] = (f1[a[u][i].first] + f1[u]) % p;
			}
		}
	}
	d2[n] = 0;
	f2[n] = 1;
	s.insert(make_pair(0, n));
	while (s.size())
	{
		int u = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < b[u].size(); i++)
		{
			if (d2[b[u][i].first] > d2[u] + b[u][i].second)
			{
				f2[b[u][i].first] = f2[u];
				s.erase(make_pair(d2[b[u][i].first], b[u][i].first));
				d2[b[u][i].first] = d2[u] + b[u][i].second;
				s.insert(make_pair(d2[b[u][i].first], b[u][i].first));
			}
			else if (d2[b[u][i].first] == d2[u] + b[u][i].second)
			{
				f2[b[u][i].first] = (f2[b[u][i].first] + f2[u]) % p;
			}
		}
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d1[i] + d2[i] == d1[n] && f1[i] * f2[i] % p == f1[n])
		{
			c++;
		}
	}
	printf("%d\n", c);
	for (int i = 1; i <= n; i++)
	{
		if (d1[i] + d2[i] == d1[n] && f1[i] * f2[i] % p == f1[n])
		{
			printf("%d ", i);
		}
	}
	return 0;
}