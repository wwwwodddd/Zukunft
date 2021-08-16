#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, ex, ey;
char s[1020][1020];
int d[1020][1020];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
deque<pair<int, int> > q;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	scanf("%d%d", &n, &m);
	sx = 0;
	sy = 0;
	ex = n - 1;
	ey = m - 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	memset(d, -1, sizeof d);
	d[sx][sy] = 0;
	q.push_back(make_pair(sx, sy));
	while (q.size() > 0)
	{
		pair<int, int> u = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (in(nx, ny) && s[nx][ny] != '#')
			{
				if (d[nx][ny] == -1 || d[nx][ny] > d[u.first][u.second])
				{
					d[nx][ny] = d[u.first][u.second];
					q.push_front(make_pair(nx, ny));					
				}
			}
		}
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				if (abs(dx) + abs(dy) == 4)
				{
					continue;
				}
				int nx = u.first + dx;
				int ny = u.second + dy; 
				if (in(nx, ny))
				{
					if (d[nx][ny] == -1)
					{
						d[nx][ny] = d[u.first][u.second] + 1;
						q.push_back(make_pair(nx, ny));					
					}
				}
			}
		}
	}
	printf("%d\n", d[ex][ey]);
	return 0;
}
