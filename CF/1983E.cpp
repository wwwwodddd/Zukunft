#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long pw(long long x, long long y)
{
	long long re = 1;
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
	int t, n, k, v;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		int m = n - k;
		long long sa = 0;
		long long sb = 0;
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &v);
			sb += v;
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &v);
			sa += v;
		}
		long long x = sa * ((m + 1) / 2) % p * pw(m, p - 2) % p;
		long long y = sa * (m / 2) % p * pw(m, p - 2) % p;
		x += sb * ((m + 2) / 2) % p * pw(m + 1, p - 2) % p;
		y += sb * ((m + 1) / 2) % p * pw(m + 1, p - 2) % p;
		printf("%lld %lld\n", x % p, y % p);
	}
	return 0;
}
