#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> a[500020];
int f[500020][20];
int d[500020];
void dfs(int x, int y)
{
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int up(int x, int d)
{
	for (int i = 0; i < 20; i++)
	{
		if (d >> i & 1)
		{
			x = f[x][i];
		}
	}
	if (x == 0)
	{
		x = -1;
	}
	return x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x].push_back(i);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", up(x, y));
	}
	return 0;
}