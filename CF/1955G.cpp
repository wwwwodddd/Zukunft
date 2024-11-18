#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[120][120];
bool f[120][120];
bool F(int x)
{
	f[0][1] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = ((f[i - 1][j] || f[i][j - 1]) && a[i][j] % x == 0);
		}
	}
	return f[n][m];
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		int z = 1;
		for (int k = 1; k * k <= a[1][1]; k++)
		{
			if (a[1][1] % k == 0)
			{
				if (F(k))
				{
					z = max(z, k);
				}
				if (F(a[1][1] / k))
				{
					z = max(z, a[1][1] / k);
				}
			}
		}
		printf("%d\n", z);
	}
	return 0;
}