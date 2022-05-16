#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10020][12];
int f[10020][12][12];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	memset(f, 0xc0, sizeof f);
	f[0][0][m - 1] = a[0][0] + a[0][m - 1];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = j + 1; k < m; k++)
			{
				for (int j1 = max(j - 1, 0); j1 < min(j + 2, m); j1++)
				{
					for (int k1 = max(k - 1, j1 + 1); k1 < min(k + 2, m); k1++)
					{
						f[i][j][k] = max(f[i][j][k], f[i - 1][j1][k1] + a[i][j] + a[i][k]);
					}
				}
			}
		}
	}
	printf("%d\n", f[n - 1][0][m - 1]);
	return 0;
}
