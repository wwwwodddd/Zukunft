#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int g = 3;
typedef long long ll;
int n, m, l;
ll a[262145];
ll b[262145];
ll c[262145];
int r[262145];
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
void inv()
{
	b[0] = pw(a[0], p - 2);
	int k = 1;
	while (k <= n)
	{
		k *= 2;
		l = k * 2;
		for (int i = 0; i < l; i++)
		{
			r[i] = r[i >> 1] >> 1 | (i & 1 ? (l >> 1) : 0);
		}
		for (int i = 0; i < k; i++)
		{
			c[i] = a[i];
		}
		FFT(c, 1);
		FFT(b, 1);
		for (int i = 0; i < l; i++)
		{
			b[i] = b[i] * (2 - c[i] * b[i] % p + p) % p;
		}
		FFT(b, -1);
		for (int i = k; i < l; i++)
		{
			b[i] = 0;
		}
	}
}
int main()
{
	n = read();
	for (int i = 0; i < n; i++)
	{
		a[i] = read();
	}
	inv();
	for (int i = 0; i < n; i++)
	{
		printf("%lld%c", b[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}