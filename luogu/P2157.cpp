#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1020];
int b[1020];
int f[1020][257][17];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
		}
		memset(f, 0x3f, sizeof f);
		for (int i = 0, j = n - 1; i <= j; i++)
		{
			f[0][1 << i][i + 8] = 0;
			j = min(j, i + b[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 256; j++)
			{
				for (int k = -8; k < 8; k++)
				{
					if (f[i][j][k + 8] == 0x3f3f3f3f)
					{
						continue;
					}
					if (j & 1)
					{
						int &u = f[i + 1][j >> 1][k + 7];
						u = min(u, f[i][j][k + 8]);
					}
					else
					{
						int o = n - 1;
						for (int l = 0; l < 8 && i + l <= o; l++)
						{
							if (~j >> l & 1)
							{
								o = min(o, i + l + b[i + l]);
								int &u = f[i][j | 1 << l][l + 8];
								u = min(u, f[i][j][k + 8] + (a[i + k] ^ a[i + l]));
							}
						}
					}
				}
			}
		}
		int z = 1e9;
		for (int k = -8; k < 0; k++)
		{
			z = min(z, f[n][0][k + 8]);
		}
		printf("%d\n", z);
	}
	return 0;
}