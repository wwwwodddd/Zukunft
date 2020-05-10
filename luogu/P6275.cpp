#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inv2 = 500000004;
int n;
int f[2020][2020]; // (i, j - 1) -> (i, j)
int g[2020][2020]; // (i - 1, j) -> (i, j)
char s[2020][2020];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		f[0][i] = 1;
		g[i][0] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = f[i][j-1];
			g[i][j] = g[i-1][j];
			if (s[i-1][j-1] != 'W')
			{
				f[i][j] = (f[i][j] + (long long)g[i][j-1] * inv2) % mod;
				g[i][j] = (g[i][j] + (long long)f[i-1][j] * inv2) % mod;
			}
		}
	}
	int ans = (f[n][n] + g[n][n]) % mod;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '.')
			{
				ans = ans * 2 % mod;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}