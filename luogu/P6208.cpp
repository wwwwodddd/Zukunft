#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[120][120];
int f[120][120];
int main()
{
	memset(f, 0xc0, sizeof f);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	f[0][0] = 0;
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][j] = max(max(f[i-1][j-1], f[i+1][j-1]), f[i][j-1]) + a[i][j];
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}