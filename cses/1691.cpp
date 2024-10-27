#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[200020];
vector<int> z;
int v[200020];
int d[200020];
void dfs(int x)
{
	while (a[x].size() > 0)
	{
		auto y = a[x].back();
		a[x].pop_back();
		if (!v[y.second])
		{
			v[y.second] = true;
			dfs(y.first);
		}
	}
	z.push_back(x);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
		d[x]++;
		d[y]++;
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] & 1)
		{
			z.clear();
		}
	}
	if (z.size() == m + 1 && z[0] == 1)
	{
		for (auto i : z)
		{
			cout << i << " ";
		}
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	return 0;
}
