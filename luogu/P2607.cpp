#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[1000020];
int p[1000020];
int f[1000020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
pair<long long, long long> dfs(int x, int y)
{
	pair<long long, long long> u = make_pair(0, p[x]);
	for (int i : a[x])
	{
		if (i != y)
		{
			pair<long long, long long> v = dfs(i, x);
			u.first += max(v.first, v.second);
			u.second += v.first;
		}
	}
	return u;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	vector<pair<int, int> > e;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d%d", &p[i], &x);
		if (F(i) != F(x))
		{
			a[i].push_back(x);
			a[x].push_back(i);
			f[F(i)] = F(x);
		}
		else
		{
			e.push_back(make_pair(i, x));
		}
	}
	long long z = 0;
	for (auto i : e)
	{
		z += max(dfs(i.first, 0).first, dfs(i.second, 0).first);
	}
	printf("%lld\n", z);
	return 0;
}