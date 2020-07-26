#include <bits/stdc++.h>
using namespace std;
int n, z, s;
int a[30];
int f[30];
int p[30];
int g[30][30];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			scanf("%d", &g[i][j]);
		}
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (g[i][j] && f[i] < f[j])
			{
				f[i] = f[j];
				p[i] = j;
			}
		}
		f[i] += a[i];
		if (z < f[i])
		{
			z = f[i];
			s = i;
		}
	}
	for (int i = s; i > 0; i = p[i])
	{
		printf("%d ", i);
	}
	printf("\n%d\n", z);
	return 0;
}