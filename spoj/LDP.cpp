#include <bits/stdc++.h>
using namespace std;
int v[40020];
int p[40020], pc;
int n = 40000, x;
map<int, int> f, g;
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			p[pc++] = i;
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		for (int j = 0; j < pc && p[j] * p[j] <= x; j++)
		{
			int c = 0;
			while(x % p[j] == 0)
			{
				c++;
				x /= p[j];
			}
			if (c > 0)
			{
				f[p[j]] = max(f[p[j]], c);
				g[p[j]] += c;
			}
		}
		if (x > 1)
		{
			f[x] = max(f[x], 1);
			g[x]++;
		}
	}
	long long z = 1;
	for (auto i : f)
	{
		for (int j = i.second; j < g[i.first]; j++)
		{
			z = z * i.first % 1000000009;
		}
	}
	printf("%lld\n", z);
	return 0;
}