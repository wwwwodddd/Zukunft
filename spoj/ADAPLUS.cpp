#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[2020][2020];
int l[2020][2020];
int r[2020][2020];
int u[2020][2020];
int d[2020][2020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= n + 1; j++)
			{
				l[i][j] = r[i][j] = u[i][j] = d[i][j] = 0;
			}
		}
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s[i] + 1);
			for (int j = 1; j <= n; j++)
			{
				if (s[i][j] == '#')
				{
					l[i][j] = l[i][j - 1] + 1;
					u[i][j] = u[i - 1][j] + 1;
				}
			}
		}
		for (int i = n; i > 0; i--)
		{
			for (int j = n; j > 0; j--)
			{
				if (s[i][j] == '#')
				{
					r[i][j] = r[i][j + 1] + 1;
					d[i][j] = d[i + 1][j] + 1;
					z = max(z, min(min(l[i][j], u[i][j]), min(r[i][j], d[i][j])));
				}
			}
		}
		printf("%d\n", z);
	}
	return 0;
}