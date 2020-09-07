#include <bits/stdc++.h>
using namespace std;
deque<int> q;
int n, sx, sy, x, y;
int a[1020][1020];
int d[1020][1020];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool in(int x, int y)
{
	return 0 <= x && x < 1002 && 0 <= y && y < 1002;
}
int main()
{
	scanf("%d%d%d", &n, &sx, &sy);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	memset(d, -1, sizeof d);
	q.push_back(0);
	q.push_back(0);
	d[0][0] = 0;
	while (q.size() > 0)
	{
		x = q.front();
		q.pop_front();
		y = q.front();
		q.pop_front();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (in(nx, ny) && (d[nx][ny] == -1 || d[nx][ny] > d[x][y] + a[nx][ny]))
			{
				d[nx][ny] = d[x][y] + a[nx][ny];
				if (a[nx][ny])
				{
					q.push_back(nx);
					q.push_back(ny);
				}
				else
				{
					q.push_front(ny);
					q.push_front(nx);
				}
			}
		}
	}
	printf("%d\n", d[sx][sy]);
	return 0;
}