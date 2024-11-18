#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, q, c;
map<int, int> h;
long f[10020];
long g[10020];
long s[10020];
long pw(long x, long y)
{
	long re = 1;
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
void renyi(int m)
{
	for (int i = 1; i <= c; i++)
	{
		g[i] = f[i] * pw(i, m) % p;
		s[i] = (s[i - 1] + f[i]) % p;
	}
	if (m > 0)
	{
		for (int i = 1; i <= c; i++)
		{
			g[i] = (g[i] + s[i - 1] * (pw(i, m) - pw(i - 1, m) + p) % p) % p;
		}
	}
	for (int i = 1; i <= c; i++)
	{
		f[i] = g[i];
	}
}
void xiao(int m)
{
	for (int i = 1; i <= c; i++)
	{
		f[i] = f[i] * pw(i, m) % p;
	}
}
void da()
{
	for (int i = 1; i <= c; i++)
	{
		s[i] = (s[i - 1] + f[i]) % p;
	}
	for (int i = 1; i <= c; i++)
	{
		f[i] = s[i - 1];
	}
}
void print()
{
	for (int i = 1; i <= c; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;
}
int main()
{
	cin >> n >> q >> c;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		if (h.count(y))
		{
			h[y] = min(h[y], x);
		}
		else
		{
			h[y] = x;
		}
	}
	f[1] = 1;
	int l = 0;
	for (pair<int, int> i : h)
	{
		renyi(i.second - l);
		xiao(i.first - i.second - 1);
		da();
		l = i.first;
	}
	renyi(n - l);
	long z = 0;
	for (int i = 1; i <= c; i++)
	{
		z = (z + f[i]) % p;
	}
	cout << z << endl;
	return 0;
}