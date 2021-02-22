#include <bits/stdc++.h>
using namespace std;
const int p = 10007;
int a[50020];
int f[50020];
int g[50020];
int n, m, z;
int ok(int x)
{
	int w = 0, p = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > x)
		{
			return 0;
		}
		p += a[i];
		if (p > x)
		{
			w++;
			p = a[i];
		}
	}
	return w <= m;
}
int main()
{
	scanf("%d%d", &n, &m);
	int L = 0, R = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		R += a[i];
	}
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%d ",R);
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	f[0] = 1;
	for (int i = 1; i <= m + 1; i++)
	{
		memcpy(g, f, sizeof g);
		for(int j = 0, k = 0, s = 0; j <= n; s += g[j++])
		{
			while (a[j] - a[k] > R)
			{
				s -= g[k++];
			}
			f[j] = s % p;
		}
		z += f[n];
	}
	printf("%d\n", z % p);
	return 0;
}