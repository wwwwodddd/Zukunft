#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[120], b[120];
int f[120][120];
int g[5][5] = {
{ 5,-1,-2,-1,-3},
{-1, 5,-3,-2,-4},
{-2,-3, 5,-2,-2},
{-1,-2,-2, 5,-1},
{-3,-4,-2,-1, 0},
};
int _(char c)
{
	return (c > 'A') + (c > 'C') + (c > 'G');
}
int main()
{
	scanf("%d%s%d%s", &n, a + 1, &m, b + 1);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0)
			{
				f[i][j] = 0;
			}
			else if (i == 0)
			{
				f[i][j] = f[i][j - 1] + g[4][_(b[j])];
			}
			else if (j == 0)
			{
				f[i][j] = f[i - 1][j] + g[_(a[i])][4];
			}
			else
			{
				f[i][j] = max(f[i - 1][j - 1] + g[_(a[i])][_(b[j])],
				max(f[i][j - 1] + g[4][_(b[j])], f[i - 1][j] + g[_(a[i])][4]));
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
