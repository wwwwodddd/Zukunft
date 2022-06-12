#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int g = 3;
typedef long long ll;
using poly = vector<ll>;
int n, m;
vector<int> r;
ll d[2097153];
int o[2097153];
int v[2097153];
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
void FFT(vector<ll> &a, int o, int l)
{
	assert(r.size() == l);
	assert(a.size() == l);
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
poly mul(poly a, poly b, int t = 0)
{
	int l = 1 << (32 - __builtin_clz(a.size() + b.size() + 1));
	r.resize(l);
	for (int i = 0; i < l; i++)
	{
		r[i] = r[i >> 1] >> 1 | (i & 1 ? (l >> 1) : 0);
	}
	a.resize(l);
	b.resize(l);
	FFT(a, 1, l);
	FFT(b, 1, l);
	for (int i = 0; i < l; i++)
	{
		a[i] = a[i] * b[i] % p;
	}
	FFT(a, -1, l);
	if (t > 0)
	{
		for (int i = t; i < a.size(); i++)
		{
			a[i % t] = (a[i % t] + a[i]) % p;
		}
		a.resize(t);
	}
	return a;
}
poly coef(int n, int m)
{
	poly u(n), v(n);
	u[0] = v[0] = 1;
	u[1 % n]++;
	if (m == 0)
	{
		return v;
	}
	poly r = coef(n, m / 2);
	r = mul(r, r, n);
	if (m & 1)
	{
		r = mul(r, u, n );
	}
	return r;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &d[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &o[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			poly a;
			vector<int> q;
			for (int j = i; !v[j]; j = o[j])
			{
				a.push_back(d[j]);
				q.push_back(j);
				v[j] = 1;
			}
			reverse(a.begin(), a.end());
			reverse(q.begin(), q.end());
			poly c = coef(a.size(), m);
			a = mul(a, c, a.size());
			for (int j = 0; j < q.size(); j++)
			{
				d[q[j]] = a[j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld%c", d[i], i == n ? '\n' : ' ');
	}
	return 0;
}