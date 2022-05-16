#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
const int inv2 = (p + 1) / 2;
int t, n;
long long c[2520][2520];
int main()
{
	n = 2500;
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				z = (z + __gcd(i, j) * c[n][i] % p * c[n][j]) % p;
			}
			z = (z + i * c[n][i] % p * (c[n][i] - 1) % p * inv2) % p;
		}
		printf("%lld\n", z);
	}
	return 0;
}