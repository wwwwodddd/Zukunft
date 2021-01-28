#include <bits/stdc++.h>
using namespace std;
int f[60][20020];
int u[60], d[60];
int n, m, s;
int main()
{
	memset(f, 0x3f, sizeof f);
	scanf("%d%d%d", &n, &m, &s);
	f[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &u[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < s + u[i]; j++)
		{
			f[i][j + 1] = min(f[i][j + 1], f[i][j] + d[i]);
		}
		for (int j = 0; j <= s; j++)
		{
			f[i + 1][j] = f[i][j + u[i]] + j * m;
		}
	}
	printf("%d\n", f[n][0]);
	return 0;
}