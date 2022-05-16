#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n;
int b[2020];
int main()
{
	for (int i = b[0] = 1; i < 2010; i++)
	{
		b[i] = b[i - 1] * 2 % p;
	}
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		n *= 2;
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			z = (z + b[n - i] + p - b[n - i - n / i + 1]) % p;
		}
		printf("Case %d: %lld\n", tt, z);
	}
	return 0;
}