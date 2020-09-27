#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a, b, c, d, g, x, y;
ll mul(ll x, ll y, ll p)
{
	x = (x % p + p) % p;
	y = (y % p + p) % p;
	ll re = 0;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (re + x) % p;
		}
		x = x * 2 % p;
	}
	return re;
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}
int main()
{
	scanf("%d", &n);
	c = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a, &b);
		g = exgcd(a, c, x, y);
		x = mul(x, (d - b) / g, c / g);
		c = c / g * a;
		d = (mul(x, a, c) + b) % c;
	}
	printf("%lld\n", d);
	return 0;
}