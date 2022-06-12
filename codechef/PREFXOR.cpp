#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll G(ll n, ll m, ll k)
{
	vector<ll> f(n + 1);
	for (ll i = 0; i <= n; i++)
	{
		f[i] = i >> k & 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[j] ^= f[j - 1];
		}
	}
	return f[n];
}
ll GG(ll n, ll m, ll k)
{
	if ((n - (1LL << k)) & (m + (1LL << k)))
	{
		return 0;
	}
	return 1;
}
ll F(ll n, ll m)
{
	vector<ll> f(n + 1);
	for (int i = 0; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[j] ^= f[j - 1];
		}
	}
	return f[n];
}
ll FF(ll n, ll m)
{
	ll z = 0;
	for (int i = 0; i < 60; i++)
	{
		if (GG(n, m, i))
		{
			z |= 1LL << i;
		}
	}
	return z;
}
ll t, n, m;
int main()
{
	scanf("%lld", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld%lld", &m, &n);
		printf("%lld\n", FF(n, m));
	}
	return 0;
}