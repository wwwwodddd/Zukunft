#include <bits/stdc++.h>
#define I(x, y) x = (x + y) % p
const int p = 1000000007;
int n;
int f[6002][3002];
int g[6002][3002];
int a[6002], o[6002];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%d", a + i);
		i[o] = i;
	}
	std::stable_sort(o, o + 2 * n, [](int x, int y){return a[x] < a[y];});
	f[0][0] = 1;
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (o[i] < n)
			{
				I(f[i + 1][j + 1], f[i][j]);
				I(g[i + 1][j], f[i][j]);
				I(g[i + 1][j + 1], g[i][j]);
				I(g[i + 1][j], g[i][j]);
			}
			else
			{
				I(f[i + 1][j], f[i][j]);
				if (j > 0)
				{
					I(f[i + 1][j - 1], (long long)(f[i][j]) * j);
					I(g[i + 1][j - 1], (long long)(g[i][j]) * j);
				}
			}
		}
	}
	printf("%d\n", (f[2 * n][0] + g[2 * n][0]) % p);
	return 0;
}