#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int inv2 = (p + 1) / 2;
int n, m;
long long f[1025][2];
int c[2020][2020];
int a[11];
void inc(long long &x, long long y)
{
	x = (x + y) % p;
}
int ni(int j, int k, int l)
{
	for (int i = 0; i < k; i++)
	{
		if (~j >> i & 1)
		{
			l ^= 1;
		}
	}
	return l;
}
int main()
{
	for (int i = 0; i < 2010; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
		}
	}
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	f[0][0] = 1;
	for (int i = 0; i <= 2000; i++)
	{
		for (int j = 0; j < 1 << m; j++)
		{
			for (int l = 0; l < 2; l++)
			{
				for (int k = 0; k < m; k++)
				{
					if (~j >> k & 1)
					{
						if (i >= a[k])
						{
							int nl = ni(j, k, l);
							inc(f[j | 1 << k][nl], f[j][l] * c[n][i - a[k]]);
						}
					}
				}
			}
		}
	}
	int z = (f[(1 << m) - 1][0] + p - f[(1 << m) - 1][1]) % p;
	for (int i = 0; i < n * m; i++)
	{
		z = (long long)z * inv2 % p;
	}
	cout << z << endl;
	return 0;
}