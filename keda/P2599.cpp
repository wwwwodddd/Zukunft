#include <bits/stdc++.h>
using namespace std;
int n, x;
long long z;
int s[2020], ss;
int b[2020][2020];
int c[2020][2020];
int f[2020][2020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			scanf("%d", &x);
			if (x >= 100)
			{
				b[i][j] = b[i][j + 1] + 1;
			}
			if (x > 100)
			{
				c[i][j] = c[i][j + 1] + 1;
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		s[0] = 0;
		ss = 0;
		for (int i = 1; i <= n; i++)
		{
			while (b[s[ss]][j] > b[i][j])
			{
				ss--;
			}
			f[i][j] = f[s[ss]][j] + b[i][j] * (i - s[ss]);
			z += f[i][j];
			s[++ss] = i;
		}
	}
	for (int j = 0; j < n; j++)
	{
		s[0] = 0;
		ss = 0;
		for (int i = 1; i <= n; i++)
		{
			while (c[s[ss]][j] > c[i][j])
			{
				ss--;
			}
			f[i][j] = f[s[ss]][j] + c[i][j] * (i - s[ss]);
			z -= f[i][j];
			s[++ss] = i;
		}
	}
	printf("%lld\n", z);
	return 0;
}