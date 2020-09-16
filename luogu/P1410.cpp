#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
int n;
int a[2020];
int f[2020][2020];
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			for (int j = 1; j <= i; j++)
			{
				f[i][j] = inf;
			}
		}
		f[1][1] = -1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (f[i][j] == inf)
				{
					continue;
				}
				if (a[i + 1] > a[i])
				{
					f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
				}
				if (a[i + 1] > f[i][j])
				{
					f[i + 1][i - j + 1] = min(f[i + 1][i - j + 1], a[i]);
				}
			}
		}
		puts(f[n][n / 2] < inf ? "Yes!" : "No!");
	}
	return 0;
}