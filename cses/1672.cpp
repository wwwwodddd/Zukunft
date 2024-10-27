#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y, z;
long long d[520][520];
int main()
{
	cin >> n >> m >> q;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		d[x][y] = d[y][x] = min(d[x][y], (long long)z);
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
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		if (d[x][y] > 1e18)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << d[x][y] << endl;
		}
	}
	return 0;
}