#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, p;
ll v[3000020];
ll f[3000020];
ll C(ll n, ll m)
{
	return f[n] * v[m] % p * v[n - m] % p;
}
int main()
{
	cin >> n >> p;
	v[0] = v[1] = 1;
	for (int i = 2; i <= 3 * n; i++)
	{
		v[i] = v[p % i] * (p - p / i) % p;
	}
	for (int i = f[0] = 1; i <= 3 * n; i++)
	{
		f[i] = f[i - 1] * i % p;
		v[i] = v[i - 1] * v[i] % p;
		assert(f[i] * v[i] % p == 1);
	}
	ll zero = 1;
	ll one = (f[2 * n] * 2 - f[n] - 1) % p;
	if (one < 0)
	{
		one += p;
	}
	ll two = (C(2 * n, n) * f[n] % p * f[2 * n] * 2 - one - zero) % p;
	if (two < 0)
	{
		two += p;
	}
	for (int i = 0; i <= n; i++)
	{
		two = (two - C(n, n - i) * C(n, i) % p * C(2 * n - i, n) % p * f[n] % p * f[n] % p * f[n] % p) % p;
		if (two < 0)
		{
			two += p;
		}
	}
	ll three = (f[3 * n] - two - one - zero) % p;
	if (three < 0)
	{
		three += p;
	}
	cout << (one + two * 2 + three * 3) % p << endl;
	return 0;
}