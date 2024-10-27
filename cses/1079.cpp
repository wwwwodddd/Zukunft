#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
const int m = 1000000;
int t, a, b;
long long f[m + 20];
long long v[m + 20];
long long pw(long long x, long long y)
{
	long long re = 1;
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
long long C(int n, int m)
{
	return f[n] * v[m] % p * v[n - m] % p;
}
int main()
{
	f[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		f[i] = f[i - 1] * i % p;
	}
	v[m] = pw(f[m], p - 2);
	for (int i = m - 1; i >= 0; i--)
	{
		v[i] = v[i + 1] * (i + 1) % p;
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b;
		cout << C(a, b) << endl;
	}
	return 0;
}