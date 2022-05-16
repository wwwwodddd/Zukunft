#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		long long z = 0, x, l;
		scanf(" Case #%*d: %d %lld", &n, &l);
		for (int i = 1; i < n; i++)
		{
			scanf("%lld", &x);
			z = __gcd(z, abs(x - l));
		}
		if (z)
		{
			printf("Case #%d: %lld\n", tt, z);
		}
		else
		{
			printf("Case #%d: I can't count that high\n", tt);
		}
	}
	return 0;
}