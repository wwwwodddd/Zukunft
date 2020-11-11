#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, z = 1;
int c[351][351];
int f[351][351];
int main()
{
	scanf("%d", &n);
	f[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		z = (long long)z * n % p;
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; j + k <= n; k++)
			{
				if (k != i)
				{
					f[i][j + k] = (f[i][j + k] + (long long)f[i - 1][j] * c[n - j][k]) % p;
				}
			}
		}
	}
	printf("%d\n", (z + p - f[n][n]) % p);
	return 0;
}