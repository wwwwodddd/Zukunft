#include <bits/stdc++.h>
using namespace std;
const int p = 1234567891;
typedef long long ll;
ll read()
{
	int sign = 1;
	ll re = 0;
	char c = getchar();
	while (!isdigit(c) && c != '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		sign = -1;
	}
	else
	{
		re = c - '0';
	}
	c = getchar();
	while (isdigit(c))
	{
		re = (re * 10 + c - '0') % p;
		c = getchar();
	}
	return sign * re;
}
ll a[120];
int z[1000020], zc;
int main()
{
	int n = read();
	int m = read();
	for (int i = 0; i <= n; i++)
	{
		a[i] = read();
	}
	for (int i = 1; i <= m; i++)
	{
		ll re = 0;
		for (int j = n; j >= 0; j--)
		{
			re = (re * i + a[j]) % p;
		}
		if (re == 0)
		{
			z[zc++] = i;
		}
	}
	printf("%d\n", zc);
	for (int i = 0; i < zc; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}