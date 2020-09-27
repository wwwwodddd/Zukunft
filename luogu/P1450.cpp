#include <bits/stdc++.h>
using namespace std;
int c[4], n, d[4], s;
long long f[100010];
int main()
{
	f[0] = 1;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &c[i]);
		for (int j = c[i]; j < 100010; j++)
		{
			f[j] += f[j - c[i]];
		}
	}
	scanf("%d", &n);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &d[i]);
		}
		scanf("%d", &s);
		long long z = 0;
		for (int i = 0; i < 16; i++)
		{
			int t = s;
			for (int j = 0; j < 4; j++)
			{
				if (i >> j & 1)
				{
					t -= c[j] * (d[j] + 1);
				}
			}
			if (t >= 0)
			{
				z += __builtin_parity(i) ? -f[t] : f[t];
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}