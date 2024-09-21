#include <bits/stdc++.h>
using namespace std;
int n, p;
long long f[100020];
long long z[100020];
vector<int> a[100020];
void dfs1(int x, int y)
{
	f[x] = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs1(i, x);
			f[x] = f[x] * (f[i] + 1) % p;
		}
	}
}
void dfs2(int x, int y, long long g)
{
	z[x] = f[x] * (g + 1) % p;
	vector<long long> pre(a[x].size() + 1);
	vector<long long> suf(a[x].size() + 1);
	pre[0] = 1;
	suf[suf.size() - 1] = 1;
	for (int i = 0; i < a[x].size(); i++)
	{
		if (a[x][i] == y)
		{
			pre[i + 1] = pre[i];
		}
		else
		{
			pre[i + 1] = (f[a[x][i]] + 1) * pre[i] % p;
		}
	}
	for (int i = a[x].size() - 1; i > 0; i--)
	{
		if (a[x][i] == y)
		{
			suf[i] = suf[i + 1];
		}
		else
		{
			suf[i] = (f[a[x][i]] + 1) * suf[i + 1] % p;
		}
	}
	for (int i = 0; i < a[x].size(); i++)
	{
		if (a[x][i] != y)
		{
			dfs2(a[x][i], x, (g + 1) * pre[i] % p * suf[i + 1] % p);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}