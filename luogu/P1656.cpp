#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[200];
int n, m, x, y;
vector<pair<int, int> > z;
int dfn[200], low[200], cnt;
bool v[6000];
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	for (pair<int, int> i : a[x])
	{
		if (!dfn[i.first])
		{
			v[i.second] = 1;
			dfs(i.first);
			low[x] = min(low[x], low[i.first]);
			if (dfn[x] < low[i.first])
			{
				z.push_back(make_pair(min(x, i.first), max(x, i.first)));
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
	dfs(1);
	sort(z.begin(), z.end());
	for (pair<int, int> i: z)
	{
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}