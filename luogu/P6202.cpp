#include <bits/stdc++.h>
using namespace std;
const int mod = 98765431;
long long n;
int m;
int a[50020];
long long s;
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
	scanf("%lld%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	if (m & 1)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = (s - a[i]) % mod;
		}
		s = 0;
		for (int i = 0; i < n; i++)
		{
			s += a[i];
		}
		s %= mod;
		m--;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = (a[i] + s * (n - 2) % mod * (pw((n * (n - 2) + 1) % mod, m / 2) - 1) % mod * pw((n * (n - 2)) % mod, mod - 2)) % mod;
		printf("%d\n", a[i]);
	}
}