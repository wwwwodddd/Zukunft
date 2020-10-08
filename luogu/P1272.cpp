#include <bits/stdc++.h>
using namespace std;
vector<int> a[200];
int f[200][200];
int n, m, x, y, z = 1e9;
void dfs(int x, int y)
{
	f[x][1] = a[x].size();
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			for (int j = m; j > 0; j--)
			{
				for (int k = 1; k < j; k++)
				{
					f[x][j] = min(f[x][j], f[x][j - k] + f[i][k] - 2);
				}
			}
		}
	}
	z = min(z, f[x][m]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(f, 0x3f, sizeof f);
	dfs(1, 0);
	printf("%d\n", z);
	return 0;
}