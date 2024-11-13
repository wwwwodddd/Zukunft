#include <bits/stdc++.h>
using namespace std;
int n, x, y, l;
int p[100020];
vector<int> a[100020];
int f[100020];
int g[100020];
void dfs(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			f[x] += f[i];
			g[x] += g[i];
		}
	}
	g[x] = min(g[x], f[x]);
}
int main()
{
	cin >> n;
	assert(1 <= n && n <= 100000);
	set<int> sp;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		assert(1 <= p[i] && p[i] <= n);
		sp.insert(p[i]);
	}
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 2; i <= n; i++)
	{
		if (a[i].size() == 1)
		{
			f[i] = 1;
			l++;
		}
	}
	for (int i = 1; i <= l; i++)
	{
		g[p[i]]++;
	}
	dfs(1, 0);
	cout << g[1] << endl;
	return 0;
}