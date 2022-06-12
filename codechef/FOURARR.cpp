#include <bits/stdc++.h>
using namespace std;
const int p = 1004535809;
const int g = 3;
typedef long long ll;
int sa, sb, sc, sd, m;
ll K;
ll a[262145];
ll b[262145];
ll c[262145];
ll d[262145];
int r[262145];
ll read()
{
	ll n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		;
	for(;isdigit(c);c=getchar())
	{
		n=n*10+c-'0';
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
	sa = read();
	sb = read();
	sc = read();
	sd = read();
	K = read();
	m = 262144;
	for (int i = 0; i < m; i++)
	{
		r[i] = r[i >> 1] >> 1 | (i & 1 ? (m >> 1) : 0);
	}
	for (int i = 0; i < sa; i++)
	{
		a[read()]++;
	}
	for (int i = 0; i < sb; i++)
	{
		b[read()]++;
	}
	for (int i = 0; i < sc; i++)
	{
		c[read()]++;
	}
	for (int i = 0; i < sd; i++)
	{
		d[read()]++;
	}
	FFT(a, 1);
	FFT(b, 1);
	for (int i = 0; i < m; i++)
	{
		a[i] = a[i] * b[i] % p;
	}
	FFT(a, -1);
	FFT(c, 1);
	FFT(d, 1);
	for (int i = 0; i < m; i++)
	{
		c[i] = c[i] * d[i] % p;
	}
	FFT(c, -1);
	for (int i = 1; i < m; i++)
	{
		c[i] += c[i - 1];
	}
	ll L = -1, R = 4e10;
	while (L < R - 1)
	{
		ll M = (L + R) / 2;
		ll C = 0;
		for (ll i = 0, j = m - 1; i < m; i++)
		{
			while (i * j > M)
			{
				j--;
			}
			C += a[i] * c[j];
		}
		if (C < K)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	cout << R << endl;
	return 0;
}