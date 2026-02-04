#include <bits/stdc++.h>
using namespace std;
int d[501][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, A, B, x, y;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	scanf("%d%d", &n, &m);
	queue<int> q;
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}