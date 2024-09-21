#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
char s[1020][1020];
void dfs(int x, int y)
{
	s[x][y] = '#';
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (in(nx, ny) && s[nx][ny] == '.')
		{
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				dfs(i, j);
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}