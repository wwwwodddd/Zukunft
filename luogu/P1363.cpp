#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int vx[1520][1520];
int vy[1520][1520];
char s[1520][1520];
bool dfs(int x, int y)
{
	vx[x % n][y % m] = x;
	vy[x % n][y % m] = y;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (s[nx % n][ny % m] != '#')
		{
			if (vx[nx % n][ny % m] == 0 && vy[nx % n][ny % m] == 0)
			{
				if (dfs(nx, ny))
				{
					return true;
				}
			}
			else if (vx[nx % n][ny % m] != nx || vy[nx % n][ny % m] != ny)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while (cin >> n >> m)
	{
		int x, y;
		memset(vx, 0, sizeof vx);
		memset(vy, 0, sizeof vy);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == 'S')
				{
					x = i;
					y = j;
				}
			}
		}
		puts(dfs(n * m + x, n * m + y) ? "Yes" : "No");
	}
	return 0;
}