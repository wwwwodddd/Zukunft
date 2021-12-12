#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int B = 16;
int n, m, x, z;
ll c[65537];
void fwt(ll a[])
{
	for (int j = 0; j < B; j++)
	{
		for (int i = 0; i < 1 << B; i++)
		{
			if (i >> j & 1)
			{
				ll x = a[i ^ (1 << j)];
				ll y = a[i];
				a[i ^ (1 << j)] = (x + y) % mod;
				a[i] = (x - y + mod) % mod;
			}
		}
	}
}
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
ll spw(ll x, ll y)
{
	if (y == 0)
	{
		return 0;
	}
	else if (y & 1)
	{
		return (spw(x, y - 1) * x + 1) % mod;
	}
	else
	{
		return spw(x * x % mod, y / 2) * (x + 1) % mod;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		c[x]++;
	}
	fwt(c);
	for (int i = 0; i < 1 << B; i++)
	{
		c[i] = spw(c[i], n) * c[i] % mod;
	}
	fwt(c);
	for (int i = 1; i < 1 << B; i++)
	{
		z = (z + c[i]) % mod;
	}
	cout << z * pw(1 << B, mod - 2) % mod << endl;
	return 0;
}