#include <bits/stdc++.h>
using namespace std;
int n, m, l, sx, sy, ex, ey, x, y, z;
int a[9][9];
void dfs(int x, int y)
{
	if (!a[x][y])
	{
		return;
	}
	if (x == ex && y == ey)
	{
		z++;
		return;
	}
	a[x][y] = 0;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	a[x][y] = 1;
}
int main()
{
	cin >> n >> m >> l >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < l; i++)
	{
		cin >> x >> y;
		a[x][y] = 0;
	}
	dfs(sx, sy);
	printf("%d\n", z);
	return 0;
}