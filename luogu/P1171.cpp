#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[20][20];
int f[1048577][20];
int main()
{
	cin >> n;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
		f[1 << i][i] = a[0][i];
	}
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
	cout << f[(1 << n) - 1][0] << endl;
	return 0;
}
