#include <bits/stdc++.h>
using namespace std;
int p[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int t;
long long f[8193], k;
int main()
{
	for (int i = 0; i < 1 << 13; i++)
	{
		f[i] = 1;
		for (int j = 0; j < 13; j++)
		{
			if (i >> j & 1)
			{
				f[i] = f[i] * -p[j];
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &k);
		long long L = 0, R = 304250263527210;
		while (L < R - 1)
		{
			long long M = (L + R) / 2, c = M;
			for (int i = 0; i < 1 << 13; i++)
			{
				c -= M / f[i];
			}
			if (c < k)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		printf("%lld\n", R);
	}
	return 0;
}