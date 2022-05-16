#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
long long pw(long long x, int y)
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
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		long long z = 0, f = 1;
		for (int i = 1; i < n; i++)
		{
			z = (z + pw(i, n - i - 1) * pw(n - i, i - 1)) % p;
			f = f * i % p;
		}
		printf("%lld\n", z * f % p * n % p);
	}
	return 0;
}