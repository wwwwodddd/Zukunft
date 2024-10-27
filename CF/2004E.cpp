#include <bits/stdc++.h>
using namespace std;
int t, n = 10000000, c = 0;
int f[10000020];
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (f[i] == 0)
		{
			c++;
			for (int j = i; j <= n; j += i)
			{
				if (f[j] == 0)
				{
					f[j] = c;
				}
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		f[i] = 0;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int z = 0, x;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			z ^= f[x];
		}
		puts(z ? "Alice" : "Bob");
	}
	return 0;
}