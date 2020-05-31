#include <bits/stdc++.h>
using namespace std;
const int p = 1004535809;
const int g = 3;
typedef long long ll;
int n, m, l, t;
ll a[262145];
ll b[262145];
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
	for (int i = 0; i < m; i++)
	{
		if (i < r[i])
		{
			swap(a[i], a[r[i]]);
		}
	}
	for (int i = 1; i < m; i <<= 1)
	{
		ll d = pw(g, p - 1 + o * (p - 1) / (2 * i)); 
		for (int j = 0, w = 1; j < m; j++, w = w * d % p)
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
		for (int i = 0, im = pw(m, p - 2); i < m; i++)
		{
			a[i] = a[i] * im % p;
		}
	}
}
int main()
{
	n = read();
	l = read();
	t = read();
	m = 1 << (33 - __builtin_clz(n));
	for (int i = 0; i < m; i++)
	{
		r[i] = r[i >> 1] >> 1 | (i & 1 ? (m >> 1) : 0);
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = read();
	}
	b[0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (t)
		{
			b[i + 1] = (p - b[i]) * (l - i + p) % p * pw(i + 1, p - 2) % p;
		}
		else
		{
			b[i + 1] = b[i] * (l + i) % p * pw(i + 1, p - 2) % p;
		}
	}
	FFT(a, 1);
	FFT(b, 1);
	for (int i = 0; i < m; i++)
	{
		a[i] = a[i] * b[i] % p;
	}
	FFT(a, -1);
	for (int i = 0; i < n; i++)
	{
		printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}