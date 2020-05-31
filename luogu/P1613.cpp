#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int d[50][50];
bool g[50][50][36];
int main()
{
	cin >> n >> m;
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		g[x-1][y-1][0] = true;
		d[x-1][y-1] = 1;
	}
	for (int l = 1; l < 36; l++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (g[i][k][l-1] && g[k][j][l-1])
					{
						g[i][j][l] = true;
						d[i][j] = 1;
					}
				}
			}
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	cout << d[0][n-1] << endl;
	return 0;
}