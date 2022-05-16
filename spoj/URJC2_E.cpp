#include <bits/stdc++.h>
using namespace std;
int t, n, h, k, q, l, r;
int s[101][50001];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &k, &h, &n);
		for (int i = 0; i < k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &s[i][j]);
				s[i][j] += s[i][j - 1];
			}
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &l, &r);
			int z = 0;
			for (int j = 0; j < k; j++)
			{
				if (s[j][r] - s[j][l - 1] > h)
				{
					z++;
				}
			}
			printf("%d - %d\n", z, k - z);
		}
	}
	return 0;
}