#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1020][1020];
int d[1020][1020];
int f[1020][1020];
int g[1020][1020];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	queue<pair<int, int> > q;
	memset(d, -1, sizeof d);
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '#')
			{
				d[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (in(nx, ny))
			{
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[u.first][u.second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	priority_queue<pair<int, pair<int, int> > > p;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == 'S')
			{
				f[i][j] = 0;
				q.push(make_pair(i, j));
				g[i][j] = d[i][j] - 1;
				p.push(make_pair(g[i][j], make_pair(i, j)));
			}
		}
	}
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (in(nx, ny) && s[nx][ny] != '#' && f[u.first][u.second] + 1 <= (long long)d[nx][ny] * m)
			{
				if (f[nx][ny] == -1)
				{
					f[nx][ny] = f[u.first][u.second] + 1;
					if (f[nx][ny] < d[nx][ny] * m)
					{
						q.push(make_pair(nx, ny));
					}
					g[nx][ny] = d[nx][ny] - 1;
					p.push(make_pair(g[nx][ny], make_pair(nx, ny)));
				}
			}
		}
	}
	while (p.size())
	{
		pair<int, pair<int, int> > u = p.top();
		p.pop();
		if (u.first == 0)
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = u.second.first + dx[i];
			int ny = u.second.second + dy[i];
			if (in(nx, ny) && s[nx][ny] != '#' && g[nx][ny] == -1)
			{
				g[nx][ny] = g[u.second.first][u.second.second] - 1;
				p.push(make_pair(g[nx][ny], make_pair(nx, ny)));
			}
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g[i][j] != -1)
			{
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}