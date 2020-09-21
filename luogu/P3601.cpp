#include <bits/stdc++.h>
using namespace std;
const int mod = 666623333;
long long a[1000020];
long long f[1000020];
long long l, r;
int v[1000020];
void gao(int p)
{
	for (long long i = (l + p - 1) / p * p; i <= r; i += p)
	{
		while (a[i - l] % p == 0)
		{
			a[i - l] /= p;
		}
		f[i - l] = f[i - l] / p * (p - 1);
	}
}
long long phi(long long x)
{
	int re = x;
	for (long long i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			re = re / i * (i - 1);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x > 1)
	{
		re = re / x * (x - 1);
	}
	return re;
}
int main()
{
	scanf("%lld%lld", &l, &r);
	for (int i = 0; i <= r - l; i++)
	{
		a[i] = l + i;
		f[i] = l + i;
	}
	for (int i = 2; i <= r / i; i++)
	{
		if (!v[i])
		{
			gao(i);
		}
		for (int j = i; j <= r / j; j += i)
		{
			v[j] = i;
		}
	}
	long long z = (l + r) % mod * (r - l + 1) % mod * 333311667 % mod;
	for (int i = 0; i <= r - l; i++)
	{
		if (a[i] > 1)
		{
			f[i] = f[i] / a[i] * (a[i] - 1);
		}
		z = (z - f[i]) % mod;
	}
	printf("%lld\n", (z + mod) % mod);
	return 0;
}