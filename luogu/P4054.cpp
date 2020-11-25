#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[301][301];
int c[101][301][301];
void change(int c[301][301], int x, int y, int z)
{
	for (int i = x; i <= n; i += i & -i)
	{
		for (int j = y; j <= m; j += j & -j)
		{
			c[i][j] += z;
		}
	}
}
int query(int c[301][301], int x, int y)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		for (int j = y; j > 0; j -= j & -j)
		{
			re += c[i][j];
		}
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			change(c[a[i][j]], i, j, 1);
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int o;
		scanf("%d", &o);
		if (o == 1)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			change(c[a[x][y]], x, y, -1);
			a[x][y] = z;
			change(c[a[x][y]], x, y, +1);
		}
		else
		{
			int xa, xb, ya, yb, z;
			scanf("%d%d%d%d%d", &xa, &xb, &ya, &yb, &z);
			xa--;
			ya--;
			printf("%d\n", query(c[z], xb, yb) - query(c[z], xb, ya) - query(c[z], xa, yb) + query(c[z], xa, ya));
		}
	}
	return 0;
}