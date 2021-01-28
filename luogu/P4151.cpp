#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, ll> > a[50020];
int n, m, x, y;
ll d[50020], v[100], z;
vector<ll> f;
void dfs(int x)
{
	if (x == n)
	{
		z = d[x];
	}
	for (pair<int, ll> i: a[x])
	{
		if (d[i.first] == -1)
		{
			d[i.first] = d[x] ^ i.second;
			dfs(i.first);
		}
		else
		{
			f.push_back(d[x] ^ d[i.first] ^ i.second);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	memset(d, -1, sizeof d);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%lld", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	d[1] = 0;
	dfs(1);
	for (ll x: f)
	{
		for (int i = 60; i >= 0; i--)
		{
			if (x >> i & 1)
			{
				if (!v[i])
				{
					v[i] = x;
					break;
				}
				x ^= v[i];
			}
		}
	}
	for (int i = 60; i >= 0; i--)
	{
		if (~z >> i & 1)
		{
			z ^= v[i];
		}
	}
	printf("%lld\n", z);
	return 0;
}