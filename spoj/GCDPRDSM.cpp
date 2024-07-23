#include <bits/stdc++.h>
using namespace std;
long long z[1000020];
int f[1000020];
int t, n = 1000000;
int main()
{
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (f[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				f[j] = f[j] / i * (i - 1);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			z[j] += (long long)f[i] * j * (j / i + 1) / 2;
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%lld\n", z[n]);
	}
	return 0;
}