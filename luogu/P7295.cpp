#include <bits/stdc++.h>
using namespace std;
int n, m, t, cnt;
int xa, xb, ya, yb;
char s[2020][2020];
int vx[2020][2020];
int vy[2020][2020];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int c[2020][2020];
int a[2020][2020];
int b[2020][2020];
int v[2020][2020];

void gao(int x, int y)
{
	int xr = vx[x][y], yr = vy[x][y];
	if (xr > xa && xr <= xb && yr > ya && yr <= yb)
	{
		cnt -= !v[xr][yr]++;
	}
}

void bfs(int x, int y)
{
	queue<int> q;
	q.push(x);
	q.push(y);
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
			if (1 <= x && x <= n + 1 && 1 <= y && y <= m + 1)
			{
				if ((y == ny && a[min(x, nx)][y]) || (x == nx && b[x][min(y, ny)]))
				{
					if (!vx[nx][ny])
					{
						vx[nx][ny] = vx[x][y];
						vy[nx][ny] = vy[x][y];
						q.push(nx);
						q.push(ny);
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] != s[i][j - 1])
			{
				a[i][j]++;
			}
			if (s[i][j] != s[i - 1][j])
			{
				b[i][j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!vx[i][j])
			{
				c[i][j] = 1;
				vx[i][j] = i;
				vy[i][j] = j;
				bfs(i, j);
			}
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
		}
	}
	for (int tt = 1; tt <= t; tt++)
	{
		cnt = 1;
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		cnt += a[xb][yb] - a[xb][ya] - a[xa - 1][yb] + a[xa - 1][ya];
		cnt += b[xb][yb] - b[xb][ya - 1] - b[xa][yb] + b[xa][ya - 1];
		cnt += c[xb][yb] - c[xb][ya] - c[xa][yb] + c[xa][ya];
		cnt -= (xb - xa) * (yb - ya);
		for (int i = xa; i <= xb; i++)
		{
			gao(i, yb + 1);
			gao(i, ya);
		}
		for (int i = ya; i <= yb; i++)
		{
			gao(xb + 1, i);
			gao(xa, i);
		}
		for (int i = xa; i <= xb; i++)
		{
			v[vx[i][ya]][vy[i][ya]] = 0;
			v[vx[i][yb + 1]][vy[i][yb + 1]] = 0;
		}
		for (int i = ya; i <= yb; i++)
		{
			v[vx[xa][i]][vy[xa][i]] = 0;
			v[vx[xb + 1][i]][vy[xb + 1][i]] = 0;
		}
		printf("%d\n", cnt);
	}
	return 0;
}