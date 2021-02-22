#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[50020];
int n, m, x, y, ans;
int dfn[50020], low[50020], cnt;
bool v[300020];
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	for (pair<int, int> i: a[x])
	{
		if (!dfn[i.first])
		{
			v[i.second] = 1;
			dfs(i.first);
			low[x] = min(low[x], low[i.first]);
			if (dfn[x] < low[i.first])
			{
				ans++;
			}
		}
		else if (!v[i.second])
		{
			low[x] = min(low[x], dfn[i.first]);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			ans++;
			dfs(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}