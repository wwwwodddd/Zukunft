#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	while (scanf("%lld", &n) != EOF)
	{
		if (n == 0)
		{
			puts("0");
			continue;
		}
		long long z = 1, c = 0, m = 38;
		// 3 ** m = 1350851717672992089 > 1e18
		long long p3 = 1;
		for (int i = 0; i < m; i++)
		{
			p3 *= 3;
		}
		for (int i = m; i >= 0; i--, p3 /= 3)
		{
			if (n > p3 << c)
			{
				z += 1LL << i;
				n -= p3 << c;
				c++;
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}