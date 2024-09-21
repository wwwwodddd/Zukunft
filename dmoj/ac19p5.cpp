#include <bits/stdc++.h>
using namespace std;
int f[1501][1501];
int a[1501][1501];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
int F(int x, int y)
{
	if (f[x][y] > 0)
	{
		return f[x][y];
	}
	f[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && a[x][y] > a[nx][ny])
		{
			f[x][y] = max(f[x][y], F(nx, ny) + 1);
		}
	}
	return f[x][y];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, F(i, j));
		}
	}
	cout << ans - 1 << endl;
	return 0;
}