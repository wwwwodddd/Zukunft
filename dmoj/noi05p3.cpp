#include <bits/stdc++.h>
using namespace std;
int a[] = {19, 15, 23, 51, 279, 47, 87, 55, 62, 626, 310, 31};
int c[12], v[20][20], g[4][4], n = 12, z;
int t[20][20], f[20];
char s[20][20];
long long b[12][1000], w, u[20];
bool in(int x, int y)
{
	return x >= 0 && y >= 0 && x >= y && x < 10;
}
int fit(int dx, int dy)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (g[i][j] && (!in(i + dx, j + dy) || s[i + dx][j + dy] != '.'))
			{
				return 0;
			}
		}
	}
	return 1;
}
long long get(int dx, int dy)
{
	long long z = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (g[i][j])
			{
				z |= 1LL << v[i + dx][j + dy];
			}
		}
	}
	return z;
}
void rot()
{
	int t[4][4] = {};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			t[j][3 - i] = g[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			g[i][j] = t[i][j];
		}
	}
}
void flip()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			swap(g[i][j], g[3 - i][j]);
		}
	}
}
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int fil(int x, int y)
{
	t[x][y] = 1;
	int re = 1;
	for (int i = 0; i < 4; i++)
	{
		if (in(x + dx[i], y + dy[i]) && !t[x + dx[i]][y + dy[i]])
		{
			re += fil(x + dx[i], y + dy[i]);
		}
	}
	return re;
}
int gao(long long x)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			t[i][j] = x >> v[i][j] & 1;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (!t[i][j])
			{
				int u = fil(i, j);
				if (u < 4 || u == 6 || u == 7)
					return 0;
			}
		}
	}
	return 1;
}
void dfs(int x, long long w)
{
	if (x && !gao(w))
	{
		return;
	}
	if (x == n)
	{
		if (w == 0x7fffffffffffffLL)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					for (int k = 0; k < 12; k++)
					{
						if (u[k] >> v[i][j] & 1)
						{
							s[i][j] = 'A' + k;
						}
					}
				}
			}
			for (int k = 0; k < 10; k++)
			{
				puts(s[k]);
			}
			exit(0);
		}
	}
	else
	{
		if (u[f[x]])
		{
			dfs(x + 1, w);
		}
		else
		{
			for (int i = 0; i < c[f[x]]; i++)
			{
				if ((w & b[f[x]][i]) == 0)
				{
					u[f[x]] = b[f[x]][i];
					dfs(x + 1, w | b[f[x]][i]);
				}
			}
			u[f[x]] = 0;
		}
	}
}
bool cmp(int x, int y)
{
	return c[x] < c[y];
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			v[i][j] = z++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (s[i][j] != '.')
			{
				u[s[i][j] - 'A'] |= 1LL << v[i][j];
				w |= 1LL << v[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (u[i])
		{
			continue;
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				g[j][k] = a[i] >> j * 4 + k & 1;
			}
		}
		for (int _ = 0; _ < 2; _++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = -2; k < 10; k++)
				{
					for (int l = -2; l < 10; l++)
					{
						if (fit(k, l))
						{
							b[i][c[i]++] = get(k, l);
						}
					}
				}
				rot();
			}
			flip();
		}
		sort(b[i], b[i] + c[i]);
		c[i] = unique(b[i], b[i] + c[i]) - b[i];
	}
	for (int i = 0; i < n; i++)
	{
		f[i] = i;
	}
	sort(f + 1, f + n, cmp);
	dfs(0, w);
	puts("No solution");
	return 0;
}