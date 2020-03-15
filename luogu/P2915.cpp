#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[16];
long long f[65536][16], z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		f[1 << i][i] = 1;
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
						if (abs(a[j] - a[k]) > m)
						{
							f[i | 1 << k][k] += f[i][j];
						}
					}
				}
			}
			if (i == (1 << n) - 1)
			{
				z += f[i][j];
			}
		}
	}
	cout << z << endl;
	return 0;
}