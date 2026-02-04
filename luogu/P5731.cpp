#include <bits/stdc++.h>
using namespace std;
int n, c, x = 1, y = 1, d;
int a[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool in(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= n && a[x][y] == 0;
}
int main()
{
	scanf("%d", &n);
	while (c < n * n)
	{
		c++;
		a[x][y] = c;
		if (!in(x + dx[d], y + dy[d]))
		{
			d = (d + 1) % 4;
		}
		x += dx[d];
		y += dy[d];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}