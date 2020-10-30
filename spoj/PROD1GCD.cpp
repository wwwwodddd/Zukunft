#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int v[10000020];
int p[1000020], pc;
int t, n, m;
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
int main()
{
	n = 10000010;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			p[pc++] = i;
		}
		for (int j = 0; j < pc && p[j] <= n / i; j++)
		{
			v[i * p[j]] = p[j];
			if (v[i] == p[j])
			{
				break;
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		long long z = 1;
		for (int i = 0; i < pc && p[i] <= n && p[i] <= m; i++)
		{
			ll s = 0;
			for (ll l = p[i]; l <= n && l <= m; l *= p[i])
			{
				s += (ll)(n / l) * (m / l);
			}
			z = z * pw(p[i], s) % mod;
		}
		printf("%lld\n", z);
	}
	return 0;
}