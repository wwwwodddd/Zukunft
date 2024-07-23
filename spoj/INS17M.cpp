#include <bits/stdc++.h>
using namespace std;
const int m = 1000000;
const int p = 1000000007;
const int pp = 2000000016;
long long k;
int n, x;
long long v[m + 20];
long long f[m + 20];
void mul(long long a[2][2], long long b[2][2])
{
	long long c[2][2] = {};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, c, sizeof c);
}
long long pwr(long long x, long long y)
{
	long long re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % pp;
		}
		x = x * x % pp;
	}
	return re;
}
void pw(long long a[2][2], long long n)
{
	long long c[2][2] = {1, 0, 0, 1};
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			mul(c, a);
		}
		mul(a, a);
	}
	memcpy(a, c, sizeof c);
}
int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		v[x]++;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = i + i; j <= m; j += i)
		{
			v[i] += v[j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		v[i] = v[i] * (v[i] - 1) / 2;
	}
	for (int i = m; i > 0; i--)
	{
		for (int j = i + i; j <= m; j += i)
		{
			v[i] = (v[i] + p - v[j]) % p;
		}
	}
	long long z = 0;
	for (int i = 1; i <= m; i++)
	{
		if (v[i])
		{
			long long b[2][2] = {0, 1, 1, 1};
			pw(b, pwr(i, k));
			z = (z + v[i] * b[0][1]) % p;
		}
	}
	printf("%lld\n", z);
	return 0;
}