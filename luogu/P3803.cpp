#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int g = 3;
typedef long long ll;
int n, m, l;
ll a[2097153];
ll b[2097153];
int r[2097153];
ll read()
{
	ll n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		;
	for(;isdigit(c);c=getchar())
		n=(n*10+c-'0')%p;
	return n;
}
int pw(ll x, int y)
{
	int re = 1;
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
void FFT(ll a[], int o)
{
	for (int i = 0; i < l; i++)
	{
		if (i < r[i])
		{
			swap(a[i], a[r[i]]);
		}
	}
	for (int i = 1; i < l; i <<= 1)
	{
		ll d = pw(g, p - 1 + o * (p - 1) / (2 * i)); 
		for (int j = 0, w = 1; j < l; j++, w = w * d % p)
		{
			if (~j & i)
			{
				ll u = a[j], v = a[j ^ i] * w % p;
				a[j] = (u + v) % p;
				a[j ^ i] = (u - v + p) % p;
			}
		}
	}
	if (o == -1)
	{
		for (int i = 0, im = pw(l, p - 2); i < l; i++)
		{
			a[i] = a[i] * im % p;
		}
	}
}
int main()
{
	n = read();
	m = read();
	l = 1 << (32 - __builtin_clz(n + m + 1));
	for (int i = 0; i <= n; i++)
	{
		a[i] = read();
	}
	for (int i = 0; i <= m; i++)
	{
		b[i] = read();
	}
	for (int i = 0; i < l; i++)
	{
		r[i] = r[i >> 1] >> 1 | (i & 1 ? (l >> 1) : 0);
	}
	FFT(a, 1);
	FFT(b, 1);
	for (int i = 0; i < l; i++)
	{
		a[i] = a[i] * b[i] % p;
	}
	FFT(a, -1);
	for (int i = 0; i <= n + m; i++)
	{
		printf("%lld%c", a[i], i == n + m ? '\n' : ' ');
	}
	return 0;
}