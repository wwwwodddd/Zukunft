#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[100020];
int n, m, x, y, l;
int d[100020];
int f[100020];
int v[100020];
void dfs(int x, int y)
{
	d[x] = d[y] + 1;
	f[x] = y;
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x);
		}
	}
}
void sign(int x, int y)
{
	for (pair<int, int> &i: a[x])
	{
		if (v[x] && v[i.first])
		{
			i.second = -i.second;
		}
		if (i.first != y)
		{
			sign(i.first, x);
		}
	}
}
int dp(int x, int y)
{
	int re = 0;
	for (pair<int, int> &i: a[x])
	{
		if (i.first != y)
		{
			int u = dp(i.first, x);
			l = max(l, re + u + i.second);
			re = max(re, u + i.second);
		}
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, 1));
		a[y].push_back(make_pair(x, 1));
	}
	int z = 2 * n - 2;
	dfs(1, 0);
	int s = max_element(d + 1, d + 1 + n) - d;
	dfs(s, 0);
	int t = max_element(d + 1, d + 1 + n) - d;
	z -= d[t] - 2;
	if (m > 1)
	{
		for (int i = t;; i = f[i])
		{
			v[i] = 1;
			if (i == s)
			{
				break;
			}
		}
		sign(1, 0);
		dp(1, 0);
		z -= l - 1;
	}
	printf("%d\n", z);
	return 0;
}
