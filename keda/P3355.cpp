#include <bits/stdc++.h>
using namespace std;
int d[501][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, A, B, x, y;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
int main()
{
	scanf("%d", &n);
	queue<int> q;
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &x);
			if (x == 1)
			{
				d[i][j] = 0;
				q.push(i);
				q.push(j);
			}
		}
	}
	while (q.size())
	{
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny))
			{
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			z = max(z, d[i][j]);
		}
	}
	printf("%d\n", z);
	return 0;
}