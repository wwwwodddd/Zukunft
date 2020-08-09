#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[100020];
int n, r;
long long dfs(int x, int y)
{
	long long re = 0;
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			re += min((long long)i.second, dfs(i.first, x));
		}
	}
	return re > 0 ? re : 1e9;
}
int main()
{
	scanf("%d%d", &n, &r);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	printf("%lld\n", dfs(r, 0));
	return 0;
}