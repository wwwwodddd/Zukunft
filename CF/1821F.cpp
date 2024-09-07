#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long n, m, k;
long long b[300020];
long long f[300020];
long long v[300020];
long long z;
long long C(long long n, long long m)
{
	if (m < 0 || m > n)
	{
		return 0;
	}
	return f[n] * v[m] % p * v[n - m] % p;
}
int main()
{
	cin >> n >> m >> k;
	f[0] = v[0] = v[1] = b[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * 2 % p;
		f[i] = f[i - 1] * i % p;
		v[i] = v[i - 1] * v[i] % p;
	}
	for (int i = 0; i <= m; i++)
	{
		z = (z + (p + 1 - i % 2 * 2) * b[m - i] % p * C(n - m * k - i * k, m) % p * C(m, i) % p) % p;
	}
	cout << z << endl;
	return 0;
}