#include <bits/stdc++.h>
using namespace std;
int t, n;
int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int a[65537];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++)
		{
			int y = 0;
			long long x;
			scanf("%lld", &x);
			for (int j = 0; j < 15; j++)
			{
				if (x % p[j] == 0)
				{
					y |= 1 << j;
				}
			}
			a[y]++;
		}
		for (int j = 0; j < 15; j++)
		{
			for (int i = 0; i < 1 << 15; i++)
			{
				if (i >> j & 1)
				{
					a[i ^ (1 << j)] += a[i];
				}
			}
		}
		long long z = 0;
		for (int i = 0; i < 1 << 15; i++)
		{
			int j = __builtin_popcount(i);
			z += (long long)(j & 1 ? j - 1 : 1 - j) * a[i] * a[i];
		}
		printf("%lld\n", z);
	}
	return 0;
}