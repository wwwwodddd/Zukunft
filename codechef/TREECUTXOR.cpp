#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> a[200020];
vector<pair<int, int> > z;
void dfs(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			z.push_back(make_pair(x, i));
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
			int x, y;
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		z.clear();
		printf("%d\n", (n == 2));
		dfs(1, 0);
		for (int i = 0; i < n - 1; i++)
		{
			if (n % 2 == 0 && (i == n - 3 || i == n - 4))
			{
				printf("%d %d %d\n", z[i].first, z[i].second, z[i].first);
			}
			else
			{
				printf("%d %d %d\n", z[i].first, z[i].second, z[i].second);
			}
		}
	}
	return 0;
}