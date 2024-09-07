#include <bits/stdc++.h>
using namespace std;
int a[3001][3001];
int c[3001][3001];
int n, m, o, x, y, u, v;
void R(int x, int y, int v)
{
	for (int i = x; i <= n; i += i & -i)
	{
		for (int j = y; j <= m; j += j & -j)
		{
			c[i][j] += v;
		}
	}
}
int G(int x, int y)
{
	int q = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		for (int j = y; j > 0; j -= j & -j)
		{
			q += c[i][j];
		}
	}
	return q;
}
int main()
{
	scanf("%d%d", &n, &m);
	while (scanf("%d%d%d", &x, &y, &u), x)
	{
		if ((x + y) & 1)
		{
			u = -u;
		}
		R(x, y, u - a[x][y]);
		a[x][y] = u;
	}
	while (scanf("%d%d%d%d", &x, &y, &u, &v), x)
	{
		x--;
		y--;
		int z = G(x, y) + G(u, v) - G(x, v) - G(u, y);
		if ((x + y) & 1)
		{
			z = -z;
		}
		printf("%d\n", z);
	}
	return 0;
}
