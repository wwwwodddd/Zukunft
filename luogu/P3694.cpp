#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int f[1048577];
int s[100001][20];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		memcpy(s[i], s[i-1], sizeof s[i]);
		s[i][--x]++;
	}
	for (int i = 0; i < 1 << m; i++)
	{
		int c = 0;
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
			{
				c += s[n][j];
			}
		}
		for (int j = 0; j < m; j++)
		{
			if (~i >> j & 1)
			{
				f[i | 1 << j] = max(f[i | 1 << j], f[i] + s[c + s[n][j]][j] - s[c][j]);
			}
		}
	}
	printf("%d\n", n - f[(1 << m) - 1]);
	return 0;
}