#include <bits/stdc++.h>
using namespace std;
int n, m, x, f[120][120];
void print(int x, int y)
{
	if (x == 0)
	{
		return;
	}
	if (f[x][y] == f[x][y - 1])
	{
		print(x, y - 1);
	}
	else
	{
		print(x - 1, y - 1);
		printf("%d ", y);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = -1e9;
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			f[i][j] = max(f[i][j-1], f[i-1][j-1] + x);
		}
	}
	printf("%d\n", f[n][m]);
	print(n, m);
	printf("\n");
	return 0;
}