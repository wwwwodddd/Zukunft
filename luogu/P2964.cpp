#include <bits/stdc++.h>
using namespace std;
int n, s[2020], f[2020][2020];
int main()
{
	scanf("%d", &n);
	for (int i = n; i > 0; i--)
	{
		scanf("%d", &s[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] += s[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = f[i][j - 1];
			int k = 2 * j;
			if (k <= i)
			{
				f[i][j] = max(f[i][j], s[i] - f[i - k][k]);
			}
			k--;
			if (k <= i)
			{
				f[i][j] = max(f[i][j], s[i] - f[i - k][k]);
			}
		}
	}
	printf("%d\n", f[n][1]);
	return 0;
}