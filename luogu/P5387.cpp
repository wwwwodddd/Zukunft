#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
ll l;
int n = 1, m, s;
int a[1048577];
ll pw(ll x, ll y)
{
	ll re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
void gao()
{
	for (int i = 1; i < n; i <<= 1)
	{
		for (int j = 0; j < n; j++)
		{
			if (j & i)
			{
				int u = (a[j ^ i] + a[j]) % mod;
				int v = (a[j ^ i] + mod - a[j]) % mod;
				a[j ^ i] = u;
				a[j] = v;
			}
		}
	}
}
int main()
{
	scanf("%lld%d", &l, &m);
	for (int i = 1; i <= m; i++)
	{
		a[i - (1 << (31 - __builtin_clz(i))) + 1]++;
	}
	while (n < m)
	{
		n *= 2;
	}
	gao();
	for (int i = 0; i < n; i++)
	{
		a[i] = pw(a[i], l);
	}
	gao();
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i] * pw(n, mod - 2) % mod;
		s = (s + a[i]) % mod;
	}
	printf("%d\n", s);
	return 0;
}