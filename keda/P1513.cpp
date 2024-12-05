#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a[520][520];
bool v[520][520];
int l[520][520];
int r[520][520];
bool in(int nx, int ny)
{
	return 0 <= nx && nx < n && 0 <= ny && ny < m;
}
void dfs(int x, int y)
{
	if (v[x][y])
	{
		return;
	}
	v[x][y] = true;
	if (x == n - 1)
	{
		l[x][y] = y;
		r[x][y] = y;
	}
	else
	{
		l[x][y] = m;
		r[x][y] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && a[x][y] > a[nx][ny])
		{
			dfs(nx, ny);
			l[x][y] = min(l[x][y], l[nx][ny]);
			r[x][y] = max(r[x][y], r[nx][ny]);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int j = 0; j < m; j++)
	{
		dfs(0, j);
	}
	int cnt = 0;
	for (int j = 0; j < m; j++)
	{
		if (v[n - 1][j])
		{
			cnt++;
		}
	}
	if (cnt < m)
	{
		printf("0\n");
		printf("%d\n", m - cnt);
	}
	else
	{
		int ans = 0;
		for (int left = 0, right = 0; left < m; left = right + 1, ans++)
		{
			for (int i = 0; i < m; i++)
			{
				if (l[0][i] <= left)
				{
					right = max(right, r[0][i]);
				}
			}
		}
		printf("1\n");
		printf("%d\n", ans);
	}
	return 0;
}