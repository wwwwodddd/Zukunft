#include <bits/stdc++.h>
using namespace std;
const int m = 20;
int t;
int c[1048577];
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		memset(c, 0, sizeof c);
		int b = 0;
		c[b]++;
		scanf("%s", s);
		for (int i = 0; s[i]; i++)
		{
			b ^= 1 << (s[i] - 'a');
			c[b]++;
		}
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < 1 << m; i++)
			{
				if (i >> j & 1)
				{
					c[i ^ (1 << j)] += c[i];
				}
			}
		}
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int l;
			scanf("%d", &l);
			char o[9];
			for (int j = 0; j < l; j++)
			{
				scanf(" %c", &o[j]);
			}
			int d[33] = {};
			for (int k = 0; k < 1 << l; k++)
			{
				b = 0;
				for (int j = 0; j < l; j++)
				{
					if (k >> j & 1)
					{
						b |= 1 << (o[j] - 'a');
					}
				}
				d[k] = c[b];
			}
			for (int j = 0; j < l; j++)
			{
				for (int k = 0; k < 1 << l; k++)
				{
					if (k >> j & 1)
					{
						d[k ^ (1 << j)] -= d[k];
					}
				}
			}
			long long z = 0;
			for (int k = 0; k < 1 << l; k++)
			{
				z += d[k] * (d[k] - 1LL) / 2;
			}
			printf("%lld\n", z);
		}
	}
	return 0;
}
