#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int f[1020][257];
int z[1020];
int b[10];
int t, n;
int main()
{
	for (int i = 2; i < 10; i++)
	{
		for (int j = i; j < 10; j += i)
		{
			b[i - 2] |= 1 << (j - 2);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		f[1][b[i]]++;
	}
	for (int i = 1; i < 1010; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			f[i + 1][j] = f[i][j];
			for (int k = 0; k < 8; k++)
			{
				if (j >> k & 1)
				{
					f[i + 1][j | b[k]] = (f[i + 1][j | b[k]] + f[i][j]) % p;
				}
			}
			z[i] = (z[i] + f[i][j]) % p;
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", z[n]);
	}
	return 0;
}