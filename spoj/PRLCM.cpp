#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int inv2 = (p + 1) / 2;
int n, m, x;
long long c[1000020];
long long f[1000020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		c[x]++;
		m = max(m, x);
	}
	f[1] = 1;
	for (int i = 2; i <= m; i++)
	{
		f[i] = f[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= m; i++)
	{
		f[i] %= p;
		if (f[i] < 0)
		{
			f[i] += p;
		}
		long long s1 = 0, s2 = 0;
		for (int j = i + i; j <= m; j += i)
		{
			f[j] -= f[i];
		}
		for (int j = i; j <= m; j += i)
		{
			s1 += c[j] * j;
			s2 += c[j] * j * j;
		}
		s1 %= p;
		s2 %= p;
		z = (z + (s1 * s1 + p - s2) % p * f[i]) % p;
	}
	printf("%lld\n", z * inv2 % p);
	return 0;
}