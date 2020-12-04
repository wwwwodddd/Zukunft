#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
ll n, z;
ll a[30], b[30], c;
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
void dfs(ll x, ll y, ll d)
{
	if (d == c)
	{
		if (1 < y)
		{
			z = (z + x % mod * pw(2, n / y)) % mod;
		}
	}
	else
	{
		for (int i = 0; i <= b[d]; i++, y *= a[d])
		{
			dfs(x, y, d + 1);
			if (i == 0)
			{
				x *= a[d] - 1;
			}
			else
			{
				x *= a[d];
			}
		}
	}
}
void factor(ll n)
{
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			a[c] = i;
			while (n % i == 0)
			{
				n /= i;
				b[c]++;
			}
			c++;
		}
	}
	if (n > 1)
	{
		a[c] = n;
		b[c++] = 1;
	}
}
int main()
{
	cin >> n;
	factor(n);
	dfs(1, 1, 0);
	cout << (z + mod - n % mod + 2) % mod << endl;
	return 0;
}