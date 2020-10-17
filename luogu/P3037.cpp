#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, s, z = 1;
pair<int, pair<int, int> > e[100020];
vector<pair<int, int> > a;
int f[40020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first);
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	sort(e, e + m);
	for (int i = 0, j; i < m; i = j)
	{
		set<pair<int, int> > q;
		int u = 0, v = 0;
		for (j = i; j < m && e[i].first == e[j].first; j++)
		{
			int x = F(e[j].second.first);
			int y = F(e[j].second.second);
			if (x > y)
			{
				swap(x, y);
			}
			if (x != y)
			{
				u++;
				q.insert(make_pair(x, y));
			}
		}
		for (j = i; j < m && e[i].first == e[j].first; j++)
		{
			int x = F(e[j].second.first);
			int y = F(e[j].second.second);
			if (x != y)
			{
				s += e[j].first;
				v++;
				f[x] = y;
			}
		}
		if (v == 1)
		{
			z = (long long)z * u % mod;
		}
		else if (v == 2 && u == 3)
		{
			z = (long long)z * q.size() % mod;
		}
	}
	printf("%d %d\n", s, z);
	return 0;
}