#include <bits/stdc++.h>
using namespace std;
int t, n, f[50020];
bool isPrime(int x)
{
	if (x < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 2; i <= 50000; i++)
	{
		if (!isPrime(i))
		{
			continue;
		}
		for (int j = 50000; j >= i; j--)
		{
			f[j] = min(f[j], f[j - i] + 1);
		}
	}
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		int z = f[n];
		if (z == 0x3f3f3f3f)
		{
			z = -1;
		}
		printf("Case %d: %d\n", tt, z);
	}
	return 0;
}