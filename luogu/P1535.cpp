#include <bits/stdc++.h>
using namespace std;
int f[120][120];
int g[120][120];
char s[120][120];
int n, m, t, sx, sy, ex, ey;
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	}
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	f[sx][sy] = 1;
	for (int k = 1; k <= t; k++)
	{
		memcpy(g, f, sizeof g);
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (s[i][j] != '*')
				{
					f[i][j] += g[i+1][j];
					f[i][j] += g[i-1][j];
					f[i][j] += g[i][j+1];
					f[i][j] += g[i][j-1];
				}
			}
		}
	}
	printf("%d\n", f[ex][ey]);
	return 0;
}