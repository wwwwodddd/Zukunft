#include <bits/stdc++.h>
using namespace std;
int n, m = 1;
char c;
int f[21][3];
int g[21][3];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &c);
		c = (c < 'P') + (c < 'S');
		memcpy(g, f, sizeof g); // g = f
		memset(f, 0, sizeof f); // f = 0
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				f[j][k] = g[j][k] + (c == k);
			}
			if (j > 0)
			{
				f[j][c] = max(f[j][c], max(g[j-1][0], max(g[j-1][1], g[j-1][2])) + 1);
			}
		}
	}
	printf("%d\n", max(f[m][0], max(f[m][1], f[m][2])));
	return 0;
}