#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[60], s[60];
int f[60][60];
int g[60][60];
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &s[i]);
		s[i] += s[i - 1];
	}
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[c][c] = 0;
	g[c][c] = 0;
	for (int j = 1; j <= n; j++)
	{
		for (int i = j - 1; i > 0; i--)
		{
			int u = s[n] - s[j] + s[i];
			int v = s[n] - s[j-1] + s[i-1];
			f[i][j] = min(f[i+1][j] + (a[i+1]-a[i]) * u, g[i+1][j] + (a[j]-a[i]) * u);
			g[i][j] = min(g[i][j-1] + (a[j]-a[j-1]) * v, f[i][j-1] + (a[j]-a[i]) * v);
		}
	}
	printf("%d\n", min(f[1][n], g[1][n]));
	return 0;
}