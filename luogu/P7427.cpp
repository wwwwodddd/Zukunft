#include <bits/stdc++.h>
using namespace std;
long long a, b;
signed main()
{
	scanf("%lld%lld", &a, &b);
	long long n = sqrt(2 * (a + b));
	if (n * (n + 1) != 2 * (a + b))
	{
		puts("No");
	}
	else
	{
		printf("%d", n);
		for (int i = n; i >= 1; i--)
		{
			if (a >= i)
			{
				printf(" %d", i), a -= i;
			}
		}
	}
	return 0;
}