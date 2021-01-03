#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 19940417;
int n, m;
ll Q(ll x)
{
	ll z = 0;
	for (ll i = 1; i <= x; i++)
	{
		ll xi = x / i, t = x / xi;
		z = (z + (t - i + 1) * x - (i + t) * (t - i + 1) / 2 * xi) % p;
		i = t;
	}
	return z;
}
ll K(ll x,ll y)
{
	ll z = 0;
	for (ll i = 1; i <= min(x, y); i++)
	{
		ll xi = x / i, yi = y / i, t = min(x / xi, y / yi), l = t - i;
		z = (z + (x % t) * (y % t) % p * (l + 1)) % p;
		z = (z + (y % t * xi + x % t * yi) % p * (l * (l + 1) / 2 % p)) % p;
		z = (z + xi * yi % p * (l * (l + 1) % (6 * p) * (2 * l + 1 ) / 6 % p)) % p;
		i = t;
	}
	return z;
}
int main()
{
	scanf("%d%d", &n, &m);
	printf("%lld\n", (Q(n) * Q(m) + p - K(n, m)) % p);
	return 0;
}