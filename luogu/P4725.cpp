#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int g = 3;
typedef long long ll;
int n;
ll a[262145];
ll b[262145];
ll c[262145];
ll d[262145];
ll v[262145];
int r[262145];
ll read()
{
	ll n = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
	{
	}
	for (; isdigit(c); c = getchar())
	{
		n = (n * 10 + c - '0') % p;
	}
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
void fft(ll a[], int n, int o)
{
	for (int i = 0; i < n; i++)
	{
		if (i < r[i])
		{
			swap(a[i], a[r[i]]);
		}
	}
	for (int i = 1; i < n; i <<= 1)
	{
		ll d = pw(g, p - 1 + o * (p - 1) / (2 * i));
		for (int j = 0, w = 1; j < n; j++, w = w * d % p)
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
		for (int i = 0, im = pw(n, p - 2); i < n; i++)
		{
			a[i] = a[i] * im % p;
		}
	}
}
void inv(ll a[], ll b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	b[0] = pw(a[0], p - 2);
	for (int k = 1, l; k < n;)
	{
		k *= 2;
		l = k * 2;
		for (int i = 0; i < l; i++)
		{
			r[i] = r[i >> 1] >> 1 | (i & 1 ? (l >> 1) : 0);
		}
		for (int i = 0; i < k; i++)
		{
			v[i] = a[i];
		}
		for (int i = k; i < l; i++)
		{
			v[i] = 0;
		}
		fft(v, l, 1);
		fft(b, l, 1);
		for (int i = 0; i < l; i++)
		{
			b[i] = b[i] * (2 - v[i] * b[i] % p + p) % p;
		}
		fft(b, l, -1);
		for (int i = k; i < l; i++)
		{
			b[i] = 0;
		}
	}
}
void derivative(ll a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		a[i - 1] = a[i] * i % p;
	}
	a[n - 1] = 0;
}
void integrate(ll a[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		a[i] = a[i - 1] * pw(i, p - 2) % p;
	}
	a[0] = 0;
}
void mul(ll a[], ll b[], int n)
{
	int l = 1 << (32 - __builtin_clz(2 * n));
	for (int i = 0; i < l; i++)
	{
		r[i] = r[i >> 1] >> 1 | (i & 1 ? (l >> 1) : 0);
	}
	fft(a, l, 1);
	fft(b, l, 1);
	for (int i = 0; i < l; i++)
	{
		a[i] = a[i] * b[i] % p;
	}
	fft(a, l, -1);
}
int main()
{
	n = read();
	for (int i = 0; i < n; i++)
	{
		a[i] = read();
	}
	inv(a, b, n);
	derivative(a, n);
	mul(a, b, n);
	integrate(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}