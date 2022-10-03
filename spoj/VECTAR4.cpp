#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &n);
		long long L = 1;
		long long R = 1e9 + 7;
		while (L < R - 1)
		{
			long long M = (L + R) / 2;
			if (M * M <= n)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		if (n == L * L)
		{
			printf("%lld\n", 2 * L - 1);
		}
		else if (n <= L * (L + 1))
		{
			printf("%lld\n", 2 * L);
		}
		else
		{
			printf("%lld\n", 2 * L + 1);
		}
	}
	return 0;
}