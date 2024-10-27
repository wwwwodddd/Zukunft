#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[200020];
int n, x, y;
int d[200020];
int e[200020];
void dfs(int x, int y, int d[])
{
	d[x] = d[y] + 1;
	for (pair<int, int> i : a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x, d);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, 1));
		a[y].push_back(make_pair(x, 1));
	}
	dfs(1, 0, d);
	int s = max_element(d + 1, d + 1 + n) - d;
	dfs(s, 0, d);
	int t = max_element(d + 1, d + 1 + n) - d;
	dfs(t, 0, e);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", max(d[i], e[i]) - 1);
	}
	return 0;
}