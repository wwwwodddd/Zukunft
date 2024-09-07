#include <bits/stdc++.h>
using namespace std;
int f[30][30];
int n, m, l, x, y;
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> y;
		f[x][y] = -1;
	}
	f[1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (f[i][j] != -1)
			{
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
			else
			{
				f[i][j] = 0;
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}