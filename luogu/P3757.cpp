#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
int f[220][220];
int g[220];
int sz[220];
int comb[220][220];
char c[220];
void merge(int x, int y)
{
	if (sz[y] == 0)
	{
		return;
	}
	memset(g, 0, sizeof g);
	if (c[y] == '<') // h[x] < h[y]
	{
		for (int j = 1; j <= sz[x]; j++)
		{
			for (int k = 1; k <= sz[y]; k++)
			{
				for (int l = j; l <= j + k - 1; l++)
				{
					g[l] = (g[l] + (long long)f[x][j] * f[y][k] % p * comb[l - 1][j - 1] % p * comb[sz[x] + sz[y] - l][sz[x] - j]) % p;
				}
			}
		}
	}
	else if (c[y] == '>') // h[x] > h[y]
	{
		for (int j = 1; j <= sz[x]; j++)
		{
			for (int k = 1; k <= sz[y]; k++)
			{
				for (int l = j + k; l <= sz[y] + j; l++)
				{
					g[l] = (g[l] + (long long)f[x][j] * f[y][k] % p * comb[l - 1][j - 1] % p * comb[sz[x] + sz[y] - l][sz[x] - j]) % p;
				}
			}
		}
	}
	for (int i = 0; i <= sz[x] + sz[y]; i++)
	{
		f[x][i] = g[i];
	}
	sz[x] += sz[y];
}
int main()
{
	scanf("%d%s", &n, c + 2);
	for (int i = 0; i <= n; i++)
	{
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
		}
	}
	for (int i = n; i > 0; i--)
	{
		f[i][1] = 1;
		sz[i] = 1;
		merge(i, 2 * i + 1);
		merge(i, 2 * i);
	}
	int z = 0;
	for (int j = 1; j <= n; j++)
	{
		z = (z + f[1][j]) % p;
	}
	printf("%d\n", z);
	return 0;
}
