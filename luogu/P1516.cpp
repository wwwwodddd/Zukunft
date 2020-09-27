#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, m, n, l, c, d, g, t, r;
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
	cin >> x >> y >> m >> n >> l;
	c = x - y;
	d = n - m;
	if (d < 0)
	{
		c = -c;
		d = -d;
	}
	g = exgcd(d, l, t, r);
	if (c % g == 0)
	{
		t = c / g * t % (l / g);
		if (t < 0)
		{
			t += l / g;
		}
		printf("%lld\n", t);
	}
	else
	{
		printf("Impossible\n");
	}
}