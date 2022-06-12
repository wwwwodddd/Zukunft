#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[120][120];
char z[120][120];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int c = 0;
			for (int k = 0; k < 9; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (in(x, y) && s[x][y] == '.')
				{
					c++;
				}
			}
			if (c)
			{
				z[i][j] = '.';
			}
			else
			{
				z[i][j] = '#';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				continue;
			}
			int c = 0;
			for (int k = 0; k < 9; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (in(x, y) && z[x][y] == '#')
				{
					c++;
				}
			}
			if (c == 0)
			{
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible");
	for (int i = 0; i < n; i++)
	{
		puts(z[i]);
	}
	return 0;
}
