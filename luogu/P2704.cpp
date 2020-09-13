#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[103][61][61];
int g[103];
int s[61], ss;
char c[20];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", c);
		for (int j = 0; j < m; j++)
		{
			if (c[j]=='H')
			{
				g[i] += 1 << j;
			}
		}
	}
	for (int i = 0; i < 1 << m; i++)
	{
		if (!(i & i >> 1) && !(i & i >> 2))
		{
			s[ss++] = i;
		}
	}
	for (int i = 1; i <= n + 2; i++)
	{
		for (int j = 0; j < ss; j++)
		{
			for (int k = 0; k < ss; k++)
			{
				for (int l = 0; l < ss; l++)
				{
					if ((s[j] & s[k]) == 0 && (s[j] & s[l]) == 0 && (s[j] & g[i]) == 0)
					{
						f[i][j][k] = max(f[i][j][k], f[i-1][k][l] + __builtin_popcount(s[j]));
					}
				}
			}
		}
	}
	printf("%d\n",f[n + 2][0][0]);
	return 0;
}