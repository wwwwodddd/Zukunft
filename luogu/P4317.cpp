#include <bits/stdc++.h>
typedef long long ll;
const int p = 10000007;
ll c[50][50], n;
ll pw(ll x, ll y)
{
	ll re = 1;
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
ll F(int x, ll n)
{
	ll z = 0;
	for (int i = 50; i-- && x >= 0;)
	{
		if (n >> i & 1)
		{
			z += c[i][x--];
		}
	}
	return z;
}
int main()
{
	for (int i = 0; i < 50; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	scanf("%lld", &n);
	n++;
	ll z = 1;
	for (int i = 2; i < 50; i++)
	{
		z = z * pw(i, F(i, n)) % p;
	}
	printf("%lld\n", z);
	return 0;
}