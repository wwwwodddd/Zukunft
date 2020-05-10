#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> a[100020];
int d[100020];
vector<pair<int, int> > e[100020];
vector<pair<int, int> > b[100020];
int c[100020];
int f[100020];
int fac[100020];
int inv[100020];
int invfac[100020];
int z[100020];
const int mod = 1000000007;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void dfs(int x, int y, int r, int h)
{
	d[h]++;
	if (x != r && a[x].size() >= 3)
	{
		if (x < r)
		{
			e[h + 1].push_back(make_pair(x, r));
		}
		return;
	}
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x, r, h + 1);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	fac[0] = 1;
	invfac[0] = 1;
	inv[1] = 1;
	z[n] = 1;
	for (int i = 2; i <= n; i++)
	{
		inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		fac[i] = (long long)fac[i - 1] * i % mod;
		invfac[i] = (long long)invfac[i - 1] * inv[i] % mod;
	}
	z[n] = fac[n];

	set<int> roots;

	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		if (a[i].size() >= 3)
		{
			roots.insert(i);
			dfs(i, 0, i, 0);
			for (int j = 0; d[j] > 0; j++)
			{
				b[j].push_back(make_pair(i, d[j]));
				d[j] = 0;
			}
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		z[i] = fac[i];
		for (pair<int, int> j: b[n - 1 - i])
		{
			c[F(j.first)] += j.second;
		}
		for (pair<int, int> j: e[n - 1 - i])
		{
			// assert(F(j.first) != F(j.second));
			int x = F(j.first);
			int y = F(j.second);
			c[y] = c[x] + c[y] - (n - 1 - i);
			f[x] = y;
			roots.erase(x);
		}
		for (int j: roots)
		{
			z[i] = (long long)z[i] * invfac[c[j] - (n - i)] % mod;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}