#include <bits/stdc++.h>
using namespace std;
int g[3000020];
int f[40] = {1, 2};
int v[40];
int n = 3000000, x, z;
int main()
{
	for (int j = 2; j < 32; j++)
	{
		f[j] = f[j - 1] + f[j - 2];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; f[j] <= i; j++)
		{
			v[g[i - f[j]]] = i;
		}
		while (v[g[i]] == i)
		{
			g[i]++;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		z ^= g[x];
	}
	puts(z ? "Ada" : "Vinit");
	return 0;
}