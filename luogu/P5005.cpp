#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, f[2][65][65];
bool ok2(int x, int y)
{
	return (x >> 1 & y << 1 & ~(x & y)) == 0
		&& (x << 1 & y >> 1 & ~(x & y)) == 0;
}
bool ok3(int x, int y, int z)
{
	return ok2(x, y) && ok2(y, z)
		&& (x >> 1 & z & ~(y >> 1 & y)) == 0
		&& (z >> 1 & x & ~(y >> 1 & y)) == 0;
}
int main()
{
	cin >> n >> m;
	f[0][0][0] = 1;
	for (int i = 1; i <= n + 2; i++)
	{
		memset(f[i & 1], 0, sizeof f[0]);
		for (int j = 0; j < 1 << m; j++)
		{
			for (int k = 0; k < 1 << m; k++)
			{
				if (!ok2(j, k))
				{
					continue;
				}
				for (int l = 0; l < 1 << m; l++)
				{
					if (ok3(j, k, l))
					{
						f[i & 1][j][k] = (f[i & 1][j][k] + f[~i & 1][k][l]) % mod;
					}
				}
			}
		}
	}
	cout << f[n & 1][0][0] << endl;
	return 0;
}