#include <bits/stdc++.h>
using namespace std;
int t, n = 2000;
double f[2020][2020];
char s[2020];
int main()
{
	f[1][0] = 4.5;
	for (int i = 1; i <= n; i++)
	{
		int d = 10;
		for (int j = 0; j <= i; j++)
		{
			while (f[i][j] < d - 1)
			{
				d -= 1;
				f[i + 1][j] += d / 10.;
			}
			f[i + 1][j] += f[i][j] * d / 10.;
			f[i + 1][j + 1] += f[i][j] * (10 - d) / 10.;
		}
		double s = 0;
		for (int j = 0; j < i; j++)
		{
			s += f[i][j];
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%s", &n, s);
		int c = 0, cc = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				c++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				printf("%.9f ", f[c][cc]);
				cc++;
			}
			else
			{
				printf("%c.00 ", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}