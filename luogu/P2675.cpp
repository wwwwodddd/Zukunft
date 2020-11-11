#include <bits/stdc++.h>
using namespace std;
const int p = 10007;
int v[p];
int f[p];
int C(int n, int m)
{
	if (n < m)
	{
		return 0;
	}
	if (n < p)
	{
		return f[n] * v[m] % p * v[n - m] % p;
	}
	return C(n % p, m % p) * C(n / p, m / p) % p;
}
int main()
{
	f[0] = 1;
	v[0] = v[1] = 1;
	for (int i = 2; i < p; i++)
	{
		v[i] = v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i < p; i++)
	{
		f[i] = f[i - 1] * i % p;
		v[i] = v[i - 1] * v[i] % p;
	}
	int n, z = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		z = (z + i % p * C(n - 1, (i - 1) / 2)) % p;
	}
	printf("%d\n", z);
	return 0;
}