#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int f[1048577][21];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (~i >> k & 1)
					{
						f[i | 1 << k][k] = min(f[i | 1 << k][k], f[i][j] + a[j][k]);
					}
				}
			}
		}
	}
	cout << f[(1 << n) - 1][n - 1] << endl;
	return 0;
}