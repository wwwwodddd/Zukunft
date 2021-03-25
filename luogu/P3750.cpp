#include <bits/stdc++.h>
using namespace std;
const int p = 100003;
int n, m, c;
int a[100020];
int f[100020];
int v[100020];
int main()
{
	scanf("%d%d", &n, &m);
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i * 2; j <= n; j += i)
		{
			a[i] ^= a[j];
		}
		c += a[i];
	}
	for (int i = n; i > 0; i--)
	{
		f[i] = ((long long)f[i + 1] * (n - i) + n) * v[i] % p;
	}
	int z = c;
	for (int i = c; i > m; i--)
	{
		z = (z - 1 + f[i]) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		z = (long long)z * i % p;
	}
	printf("%d\n", z);
	return 0;
}