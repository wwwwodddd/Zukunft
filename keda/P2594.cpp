#include <bits/stdc++.h>
using namespace std;
int n, sx, sy;
char s[30][90];
int v[30][30];
vector<pair<int, int>> p[3][3][3];
int a[3][3];
int b[3][3];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
void print()
{
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << a[j][k] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
bool win(int a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (a[i][0] == 1 && a[i][1] == 1 && a[i][2] == 2)
		{
			return true;
		}
		if (a[i][0] == 2 && a[i][1] == 1 && a[i][2] == 1)
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (a[0][i] == 1 && a[1][i] == 1 && a[2][i] == 2)
		{
			return true;
		}
		if (a[0][i] == 2 && a[1][i] == 1 && a[2][i] == 1)
		{
			return true;
		}
	}
	if (a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 2)
	{
		return true;
	}
	if (a[0][0] == 2 && a[1][1] == 1 && a[2][2] == 1)
	{
		return true;
	}
	if (a[0][2] == 1 && a[1][1] == 1 && a[2][0] == 2)
	{
		return true;
	}
	if (a[0][2] == 2 && a[1][1] == 1 && a[2][0] == 1)
	{
		return true;
	}
	return false;
}
bool ok(int ex, int ey, int ez)
{
	queue<int> q;
	q.push(sx);
	q.push(sy);
	v[sx][sy] = 1;
	while (q.size() > 0)
	{
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		// cout << x << ' ' << y << endl;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny))
			{
				if (s[nx][3 * ny] == '.' || ((s[nx][3 * ny] == 'O' || s[nx][3 * ny] == 'M') && b[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1']))
				{
					if (!v[nx][ny])
					{
						q.push(nx);
						q.push(ny);
						v[nx][ny] = 1;
					}
				}
				else if (s[nx][3 * ny] == 'O' || s[nx][3 * ny] == 'M')
				{
					if ((s[nx][3 * ny] == 'O' && a[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'] == 1) || (s[nx][3 * ny] == 'M' && a[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'] == 2))
					{
						if (v[nx][ny] == 0)
						{
							q.push(nx);
							q.push(ny);
							v[nx][ny] = 1;
						}
						if (b[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'] == 0)
						{
							b[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'] = a[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'];
							for (pair<int, int> k : p[a[s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'] ^ 3][s[nx][3 * ny + 1] - '1'][s[nx][3 * ny + 2] - '1'])
							{
								for (int l = 0; l < 4; l++)
								{
									int mx = k.first + dx[l];
									int my = k.second + dy[l];
									if (in(mx, my) && v[mx][my])
									{
										// assert(v[k.first][k.second] == 0);
										q.push(k.first);
										q.push(k.second);
										v[k.first][k.second] = 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != b[i][j])
			{
				return false;
			}
		}
	}
	for (pair<int, int> k : p[ez][ex][ey])
	{
		for (int i = 0; i < 4; i++)
		{
			int mx = k.first + dx[i];
			int my = k.second + dy[i];
			if (in(mx, my) && v[mx][my])
			{
				return true;
			}
		}
	}
	return false;
}
bool ok()
{
	if (win(a))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int u = a[i][j];
				a[i][j] = 0;
				memset(b, 0, sizeof b);
				memset(v, 0, sizeof v);
				if (u > 0 && !win(a))
				{
					if (ok(i, j, u))
					{
						return true;
					}
				}
				a[i][j] = u;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < n; j++)
		{
			if (s[i][3 * j] == 'O')
			{
				p[1][s[i][3 * j + 1] - '1'][s[i][3 * j + 2] - '1'].push_back(make_pair(i, j));
			}
			else if (s[i][3 * j] == 'M')
			{
				p[2][s[i][3 * j + 1] - '1'][s[i][3 * j + 2] - '1'].push_back(make_pair(i, j));
			}
			else if (s[i][3 * j] == 'B')
			{
				s[i][3 * j] = '.';
				s[i][3 * j + 1] = '.';
				s[i][3 * j + 2] = '.';
				sx = i;
				sy = j;
			}
		}
	}
	int z = 0;
	for (int i = 0; i < 19683; i++)
	{
		int u = i;
		for (int j = 0; j < 9; j++)
		{
			a[j / 3][j % 3] = u % 3;
			u /= 3;
		}
		if (ok())
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}