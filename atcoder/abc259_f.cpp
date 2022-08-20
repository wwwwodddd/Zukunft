#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
vector<pair<int, int> > a[300020];
int d[300020];
long long f[300020]; // <= d[i]
long long g[300020]; // <= d[i] - 1
void dfs(int x, int y)
{
	vector<long long> b;
	for (auto i : a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x);
			f[x] += f[i.first];
			g[x] += f[i.first];
			b.push_back(i.second - f[i.first] + g[i.first]);
		}
	}
	sort(b.rbegin(), b.rend());
	for (int i = 0; i < b.size() && b[i] > 0; i++)
	{
		if (i < d[x])
		{
			f[x] += b[i];
		}
		if (i < d[x] - 1)
		{
			g[x] += b[i];
		}
	}
	if (d[x] == 0)
	{
		g[x] = -1e18;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	cout << f[1] << endl;
	return 0;
}
