#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, z;
int a[256];
int f[256];
int g[256];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		memset(f, 0, sizeof f);
		f[0] = 1;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}
			memset(g, 0, sizeof g);
			for (int k = 0; k < 256; k++)
			{
				g[k] = (f[k] + f[k ^ a[j]]) % p;
			}
			swap(f, g);
		}
		for (int k = a[i]; k < 256; k++)
		{
			z = (z + f[k]) % p;
		}
	}
	printf("%d\n", z);
	return 0;
}