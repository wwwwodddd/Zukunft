#include <bits/stdc++.h>
using namespace std;
vector<int> a[200020];
int n, m, x, y, ans;
int dfn[200020], low[200020], cnt;
int cut[200020];
void dfs(int x, int y)
{
	dfn[x] = low[x] = ++cnt;
	int c = 0;
	for (int i : a[x])
	{
		if (!dfn[i])
		{
			dfs(i, x);
			low[x] = min(low[x], low[i]);
			if (y != -1 && dfn[x] <= low[i])
			{
				cut[x] = 1;
			}
			c++;
		}
		low[x] = min(low[x], dfn[i]);
	}
	if (y == -1 && c >= 2)
	{
		cut[x] = 1;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (cut[i])
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		if (cut[i])
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}