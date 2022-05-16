#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int c[100001];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		memset(c, 0, sizeof c);
		long long z = n * (n - 1LL) / 2;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			z -= c[x]++;
		}
		if (z < n * (n - 1LL) / 2)
		{
			z++;
		}
		printf("%lld\n", z);
	}
	return 0;
}