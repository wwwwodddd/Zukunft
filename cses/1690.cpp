#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, x, y;
int a[20][20];
int f[1048577][20];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x - 1][y - 1]++;
	}
	f[1][0] = 1;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (f[i][j])
			{
				for (int k = 0; k < n; k++)
				{
					if (~i >> k & 1)
					{
						f[i | 1 << k][k] = (f[i | 1 << k][k] + (long long)a[j][k] * f[i][j]) % p;
					}
				}
			}
		}
	}
	cout << f[(1 << n) - 1][n - 1] << endl;
	return 0;
}