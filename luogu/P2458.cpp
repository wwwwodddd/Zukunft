#include <bits/stdc++.h>
using namespace std;
vector<int> a[1520];
int c[1520];
int f[1520];
int g[1520];
int h[1520];
int n, m;
void dfs(int x, int y)
{
	f[x] = c[x];
	h[x] = 0;
	int mn = 1e9;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			f[x] += min(f[i], min(g[i], h[i]));
			h[x] += min(f[i], g[i]);
			mn = min(mn, f[i] - min(f[i], g[i]));
		}
	}
	g[x] = h[x] + mn;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x;
		cin >> c[x] >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
	}
	dfs(1, 0);
	cout << min(f[1], g[1]) << endl;
	return 0;
}