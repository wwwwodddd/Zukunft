#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y;
int d[50][50];
int main()
{
	cin >> n >> m;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		d[x][y] = 1;
		d[y][x] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		for (int j = 1; j <= n; j++)
		{
			if (d[x][y] == d[x][j] + d[j][y])
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
