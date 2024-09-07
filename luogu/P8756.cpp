#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, o, f[105][21][65][65];
bool ok2(int x, int y)
{
	return (x >> 2 & y) == 0 && (y >> 2 & x) == 0;
}
bool ok3(int x, int y, int z)
{
	return ok2(x, y) && ok2(y, z) && (x >> 1 & z) == 0 && (z >> 1 & x) == 0;
}
int main()
{
	cin >> m >> n >> o;
	f[0][0][0][0] = 1;
	for (int i = 1; i <= n + 2; i++)
	{
		for (int j = 0; j < 1 << m; j++)
		{
			int jc = __builtin_popcount(j);
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
						for (int p = jc; p <= o; p++)
						{
							f[i][p][j][k] = (f[i][p][j][k] + f[i - 1][p - jc][k][l]) % mod;
						}
					}
				}
			}
		}
	}
	cout << f[n + 2][o][0][0] << endl;
	return 0;
}
