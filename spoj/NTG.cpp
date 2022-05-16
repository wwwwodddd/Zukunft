#include <bits/stdc++.h>
using namespace std;
const int n = 100000;
const int p = 1000000007;
int pw(long long x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int m, t, l, r;
int f[n + 20];
int z[n + 20];
int main()
{
	scanf("%d%d", &m, &t);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (f[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				f[j] = f[j] / i * (i - 1);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		long long u = pw(i, m);
		for (int j = 1; j * i <= n; j++)
		{
			z[i * j] = (z[i * j] + u * f[j]) % p;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		z[i] = (z[i] + z[i - 1]) % p;
	}
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", (z[r] + p - z[l - 1]) % p);
	}
	return 0;
}