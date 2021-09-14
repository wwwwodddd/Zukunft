#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m;
int f[5020];
int fac[5020];
int inv[5020];
int P(int n, int m)
{
	if (n < m)
	{
		return 0;
	}
	return (long long)fac[n] * inv[n - m] % p;
}
int C(int n, int m)
{
	return (long long)fac[n] * inv[n - m] % p * inv[m] % p;
}
int main()
{
	cin >> n >> m;
	inv[0] = inv[1] = 1;
	fac[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		inv[i] = (long long)inv[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		fac[i] = (long long)fac[i - 1] * i % p;
		inv[i] = (long long)inv[i] * inv[i - 1] % p;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 0; j < m; j++)
		{
			int c = n / m + (j < n % m);
			f[i] = (long long)f[i] * P(i, c) % p;
		}
		for (int j = 1; j < i; j++)
		{
			f[i] = (f[i] - (long long)f[j] * C(i, j)) % p;
		}
		if (f[i] < 0)
		{
			f[i] += p;
		}
		cout << (long long)f[i] * inv[i] % p << endl;
	}
	return 0;
}