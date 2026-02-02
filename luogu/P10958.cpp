#include <bits/stdc++.h>
using namespace std;
int g[4][10], f[11][4];
int t;
int main()
{
	for (int i = 0; i < 3; i++)
	{
		g[i][6] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		g[3][i] = 3;
	}
	f[0][3] = 1;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				f[i][j] += f[i - 1][g[j][k]];
			}
		}
	}
	for (scanf("%d", &t); t--;)
	{
		int n, m = 1, p = 0;
		scanf("%d", &n);
		while (f[m][0] < n)
		{
			m++;
		}
		for (int i = m; i > 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				if (n > f[i - 1][g[p][j]])
				{
					n -= f[i - 1][g[p][j]];
				}
				else
				{
					printf("%d", j);
					p = g[p][j];
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}
