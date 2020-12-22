#include <bits/stdc++.h>
using namespace std;
int n, m, t, x;
int f[2520];
int g[60][2];
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++)
	{
		memset(g, 0, sizeof g);
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &x);
			for (int k = m; k > 0; k--)
			{
				g[k][0] = max(g[k][0], g[k - 1][1]);
				g[k][1] = max(g[k][1], g[k - 1][0]);
				g[k][x]++;
			}
		}
		for (int j = t; j >= 0; j--)
		{
			for (int k = 1; k <= m && k <= j; k++)
			{
				f[j] = max(f[j], f[j - k] + max(g[k][0], g[k][1]));
			}
		}
	}
	printf("%d\n", f[t]);
	return 0;
}