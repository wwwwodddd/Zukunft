#include <bits/stdc++.h>
using namespace std;
int t, n, q, l, r;
long long x;
int c[200020][32];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &x);
			x = x * 2 + 1;
			for (int j = 0; j < 32; j++)
			{
				c[i][j] = c[i - 1][j];
			}
			for (int j = 31; j >= 0; j--)
			{
				if (x >> j & 1)
				{
					c[i][j]++;
					break;
				}
			}
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d%lld", &l, &r, &x);
			x = x * 2 + 1;
			for (int j = 31; j >= 0; j--)
			{
				if (x >> j & 1)
				{
					printf("%d\n", r - l + 1 - (c[r][j] - c[l - 1][j]));
					break;
				}
			}
		}
	}
	return 0;
}