#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m;
int v[1048577];
int a[1048577];
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % mod;
		}
		x = (long long)x * x % mod;
	}
	return re;
}
int main()
{
	n = 1000000;
	m = 999983;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			a[i] = 1;
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 1 << 20; i++)
		{
			if (i >> j & 1)
			{
				a[i] = (a[i] + a[i ^ (1 << j)]) % mod;
			}
		}
	}
	for (int i = 0; i < 1 << 20; i++)
	{
		a[i] = pw(a[i], m) % mod;
	}
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 1 << 20; i++)
		{
			if (i >> j & 1)
			{
				a[i] = (a[i] + mod - a[i ^ (1 << j)]) % mod;
			}
		}
	}
	int z = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == i)
		{
			z = (z + a[i]) % mod;
		}
	}
	printf("%d\n", z);
	return 0;
}