#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
vector<int> a[5020];
int f[5020][5020];
int g[5020];
int n, m, l, x, y;
void dfs(int x, int y)
{
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			for (int j = 1; j <= m; j++)
			{
				f[x][j] = (long long)f[x][j] * (g[i] + mod - f[i][j]) % mod;
			}
		}
	}
	for (int j = 1; j <= m; j++)
	{
		g[x] = (g[x] + f[x][j]) % mod;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &l);
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &x);
			f[i][x] = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", g[1]);
	return 0;
}