#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
int t, n, x, y;
vector<int> a[100020];
pair<int, int> f[100020];
pair<int, int> g[100020];
pair<int, int> add(const pair<int, int> &a, const pair<int, int> &b)
{
	return make_pair(a.first + b.first, a.second * b.second % mod);
}
pair<int, int> min(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first < b.first)
	{
		return a;
	}
	else if (a.first > b.first)
	{
		return b;
	}
	else
	{
		return make_pair(a.first, (a.second + b.second) % mod);
	}
}
void dfs(int x, int y)
{
	f[x] = make_pair(0, 1);
	g[x] = make_pair(1, 1);
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			f[x] = add(f[x], g[i]);
			g[x] = add(g[x], min(f[i], g[i]));
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
			a[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1, 0);
		pair<int, int> z = min(f[1], g[1]);
		printf("%d %d\n", z.first, z.second);
	}
}