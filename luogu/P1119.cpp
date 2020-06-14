#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int t[220];
int d[220][220];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i < n; i++)
	{
		d[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = z;
		d[y][x] = z;
	}
	scanf("%d", &q);
	for (int l = 0, k = 0; l < q; l++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		for (; k < n && t[k] <= z; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		if (t[x] <= z && t[y] <= z && d[x][y] < 0x3f3f3f3f)
		{
			printf("%d\n", d[x][y]);
		}
		else
		{
			printf("%d\n", -1);
		}
	}
	return 0;
}