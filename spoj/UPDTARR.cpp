#include <bits/stdc++.h>
using namespace std;
int t, n, m, q, a, b;
int z[100020];
int d[400][400];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		memset(z, 0, sizeof z);
		memset(d, 0, sizeof d);
		scanf("%d%d", &n, &q);
		m = sqrt(n);
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &a, &b);
			if (b <= m)
			{
				d[b][a % b] += 1;
			}
			else
			{
				for (int i = a % b; i <= n; i += b)
				{
					z[i]++;
				}
			}
		}
		printf("Case %d:", tt);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				z[i] += d[j][i % j];
			}
			printf(" %d", z[i]);
		}
		printf("\n");
	}
	return 0;
}