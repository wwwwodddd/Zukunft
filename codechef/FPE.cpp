#include <bits/stdc++.h>
using namespace std;
int t, n, x, y;
int d[300020];
vector<int> a[300020];
long long z;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
void dfs(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			d[x] = gcd(d[x], d[i]);
		}
	}
}
void sou(int x, int y, long long s)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			s += d[i];
		}
	}
	z = max(z, s);
	for (int i : a[x])
	{
		if (i != y)
		{
			sou(i, x, s - d[i]);
		}
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &d[i]);
			a[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1, 0);
		z = 0;
		sou(1, 0, 0);
		printf("%lld\n", z);
	}
	return 0;
}