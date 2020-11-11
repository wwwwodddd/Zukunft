#include <bits/stdc++.h>
using namespace std;
int f[320][320];
int c[320][320];
int s[320];
int t, n, m, x, p;
void gao()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1 % p;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
		}
	}
	memset(s, 0, sizeof s);
	memset(f, 0, sizeof f);
	for (int i = 0; i < m; i++)
	{
		scanf("%*d%d", &x);
		s[x]++;
	}
	for (int i = n; i > 0; i--)
	{
		s[i - 1] += s[i];
		if (n - i + 1 - s[i] < 0)
		{
			puts("NO");
			return;
		}
	}
	f[n][0] = 1;
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j + s[i] <= n + 1 - i; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				f[i - 1][j] = (f[i - 1][j] + (long long)f[i][j - k] * c[j][k]) % p;
			}
		}
	}
	printf("YES %d\n", f[0][n - m]);
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		gao();
	}
}