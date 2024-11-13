#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<pair<int, int> > a[500020];
long long d[500020], ans;
void dfs(int x, int y)
{
	for (auto i : a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x);
			d[x] = max(d[x], d[i.first] + i.second);
		}
	}
	for (auto i : a[x])
	{
		if (i.first != y)
		{
			ans += d[x] - d[i.first] - i.second;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(s, 0);
	printf("%lld\n", ans);
	return 0;
}