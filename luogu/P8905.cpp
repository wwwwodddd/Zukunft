#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> s;
vector<int> a[100020];
vector<int> b;
int n, m, x, y;
int d[100020];
int f[100020];
int c[100020];
int v[100020];
long long z;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return;
	}
	c[y] += c[x];
	f[x] = y;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
		s.insert(make_pair(d[i], i));
	}
	while (s.size())
	{
		int u = s.begin()->second;
		s.erase(s.begin());
		b.push_back(u);
		v[u] = 1;
		for (int i : a[u])
		{
			if (v[i] == 0)
			{
				s.erase(make_pair(d[i], i));
				d[i]--;
				s.insert(make_pair(d[i], i));
			}
		}
	}
	memset(v, 0, sizeof v);
	for (int i = b.size() - 1; i >= 0; i--)
	{
		v[b[i]] = 1;
		long long cnt = 0;
		for (int j : a[b[i]])
		{
			if (v[j])
			{
				cnt++;
				U(b[i], j);
			}
		}
		z = max(z, cnt * c[F(b[i])]);
	}
	printf("%lld\n", z);
	return 0;
}