#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, x, y;
int a[420][420];
int c[420][420];
int f[420][420];
int main()
{
	for (int i = 0; i < 410; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (int i = 1; i <= 2 * n + 1; i++)
	{
		f[i][i - 1] = 1;
	}
	for (int i = 2 * n; i > 0; i--)
	{
		for (int j = i; j <= 2 * n; j++)
		{
			int l = j - i + 1;
			if (l & 1)
			{
				continue;
			}
			for (int k = i + 1; k <= j; k += 2)
			{
				if (a[i][k])
				{
					f[i][j] = (f[i][j] + (long long)f[i + 1][k - 1] * f[k + 1][j] % p * c[l / 2][(j - k) / 2]) % p;
				}
			}
		}
	}
	cout << f[1][2 * n] << endl;
	return 0;
}