#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> a[200020];
int f[200020];
int g[200020];
void dfs(int x, int y)
{
	int d = -1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			g[x] += max(f[i], g[i]);
			d = max(d, g[i] - f[i]);
		}
	}
	f[x] = g[x] + d + 1;
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	cout << max(f[1], g[1]) << endl;
	return 0;
}