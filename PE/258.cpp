#include <bits/stdc++.h>
using namespace std;
const int mod = 20092010;
const int m = 2000;
int z[m * 2];
int b[m * 2];
void mul(int a[], int b[])
{
	int c[m * 2] = {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i + j] = (c[i + j] + (long long)a[i] * b[j]) % mod;
		}
	}
	for (int i = 2 * m - 2; i >= m; i--)
	{
		c[i - m] = (c[i - m] + c[i]) % mod;
		c[i - m + 1] = (c[i - m + 1] + c[i]);
		c[i] = 0;
	}
	memcpy(a, c, sizeof c);
}
int main()
{
	long long n = 1e18;
	z[0] = 1;
	b[1] = 1;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			mul(z, b);
		}
		mul(b, b);
	}
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		s = (s + z[i]) % mod;
	}
	printf("%d\n", s);
	return 0;
}