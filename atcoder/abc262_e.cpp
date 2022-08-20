#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int N = 200000;
int n, m, k, o, x, y, z;
int d[N + 20];
int f[N + 20];
int v[N + 20];
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
long long C(int n, int m)
{
	if (m < 0 || m > n)
	{
		return 0;
	}
	return (long long)f[n] * v[m] % p * v[n - m] % p;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		d[x]++;
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] & 1)
		{
			o++;
		}
	}
	for (int i = f[0] = 1; i <= N; i++)
	{
		f[i] = (long long)f[i - 1] * i % p;
	}
	v[N] = pw(f[N], p - 2);
	for (int i = N; i > 0; i--)
	{
		v[i - 1] = (long long)v[i] * i % p;
	}
	for (int i = 0; i <= o && i <= k; i += 2)
	{
		z = (z + C(o, i) * C(n - o, k - i)) % p;
	}
	cout << z << endl;
	return 0;
}
