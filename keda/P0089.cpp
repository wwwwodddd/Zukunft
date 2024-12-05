#include <bits/stdc++.h>
using namespace std;
int s[50][50];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n;
bool in(int x, int y)
{
	return 0 <= x && x <= n + 1 && 0 <= y && y <= n + 1;
}

void dfs(int x, int y)
{
	s[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] == 2)
		{
			dfs(nx, ny);
		}
	}
}

int main()
{
	n = 10;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			if (s[i][j] == 0)
			{
				s[i][j] = 2;
			}
		}
	}
	dfs(0, 0);
	int z = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i][j] == 2)
			{
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}