#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[10520];
int f[10520][520];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < n; i++)
	{
		f[i+1][0] = max(f[i+1][0], f[i][0]);
		for (int j = 0; j <= m; j++)
		{
			f[i+1][j+1] = f[i][j] + d[i+1];
			f[i+j][0] = max(f[i+j][0], f[i][j]);
		}
	}
	printf("%d\n", f[n][0]);
	return 0;
}