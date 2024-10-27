#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2049][2049];
int c[2049][2049];
void change(int x, int y, int z)
{
	for (int i = x; i <= n; i += i & -i)
	{
		for (int j = y; j <= n; j += j & -j)
		{
			c[i][j] += z;
		}
	}
}
int query(int x, int y)
{
	int r = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		for (int j = y; j > 0; j -= j & -j)
		{
			r += c[i][j];
		}
	}
	return r;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; j++)
		{
			if (s[i][j] == '*')
			{
				change(i, j, 1);
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int o, x1, y1, x2, y2;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d", &x1, &y1);
			if (s[x1][y1] == '.')
			{
				s[x1][y1] = '*';
				change(x1, y1, 1);
			}
			else
			{
				s[x1][y1] = '.';
				change(x1, y1, -1);
			}
		}
		else
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
		}
	}
	return 0;
}