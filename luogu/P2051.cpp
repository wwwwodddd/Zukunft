#include <bits/stdc++.h>
using namespace std;
const int mod = 9999973;
int n, m, z, c[105][105];
long long f[105][105][105];
int main()
{
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= m - j; k++)
			{
				long long &t = f[i][j][k] = f[i - 1][j][k];
				if (k >= 1)
				{
					t = (t + f[i - 1][j + 1][k - 1] * k) % mod;
				}
				if (j >= 1)
				{
					t = (t + f[i - 1][j - 1][k] * j) % mod;
				}
				if (k >= 2)
				{
					t = (t + f[i - 1][j + 2][k - 2] * c[k][2]) % mod;
				}
				if (k >= 1)
				{
					t = (t + f[i - 1][j][k - 1] * k * j) % mod;
				}
				if (j >= 2)
				{
					t = (t + f[i - 1][j - 2][k] * c[j][2]) % mod;
				}
				if (i == n)
				{
					z = (z + t * c[m][j] % mod * c[m - j][k]) % mod;
				}
			}
		}
	}
	printf("%d\n", z);
	return 0;
}