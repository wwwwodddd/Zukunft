#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, k;
int a[100020];
int b[100020];
long long sa, sb, sc;
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
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sa = (sa + a[i]) % p;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		sb = (sb + b[i]) % p;
		sc = (sc + (long long)a[i] * b[i]) % p;
	}
	if (k == 0)
	{
		printf("%d\n", n);
	}
	else
	{
		printf("%lld\n", (sa * sb % p * pw(sc, k - 1) % p + p) % p);
	}
	return 0;
}
