#include <bits/stdc++.h>
using namespace std;
int n, x, y, c, d;
int f[1025][1025];
int g[1048577];
void gao(int x, int y, int a, int b, int l)
{
	if (l == 0)
	{
		return;
	}
	if (x < l + a && y < l + b)
	{
		c++;
		f[a + l][b + l] = c;
		f[a + l - 1][b + l] = c;
		f[a + l][b + l - 1] = c;
		gao(x, y, a, b, l / 2);
	}
	else
	{
		gao(a + l - 1, b + l - 1, a, b, l / 2);
	}
	if (x < l + a && y >= l + b)
	{
		c++;
		f[a + l][b + l] = c;
		f[a + l][b + l - 1] = c;
		f[a + l - 1][b + l - 1] = c;
		gao(x, y, a, b + l, l / 2);
	}
	else
	{
		gao(a + l - 1, b + l, a, b + l, l / 2);
	}
	if (x >= l + a && y < l + b)
	{
		c++;
		f[a + l][b + l] = c;
		f[a + l - 1][b + l] = c;
		f[a + l - 1][b + l - 1] = c;
		gao(x, y, a + l, b, l / 2);
	}
	else
	{
		gao(a + l, b + l - 1, a + l, b, l / 2);
	}
	if (x >= l + a && y >= l + b)
	{
		c++;
		f[a + l - 1][b + l - 1] = c;
		f[a + l - 1][b + l] = c;
		f[a + l][b + l - 1] = c;
		gao(x, y, a + l, b + l, l / 2);
	}
	else
	{
		gao(a + l, b + l, a + l, b + l, l / 2);
	}
}
int main()
{
	scanf("%d%d%d", &n, &x, &y);
	gao(x, y, 1, 1, 1 << (n - 1));
	for (int i = 1; i <= 1 << n; i++)
	{
		for (int j = 1; j <= 1 << n; j++)
		{
			if (f[i][j] > 0 && g[f[i][j]] == 0)
			{
				g[f[i][j]] = ++d;
			}
			printf("%d ", g[f[i][j]]);
		}
		printf("\n");
	}
	return 0;
}
