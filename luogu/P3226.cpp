#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000001;
int q[400], c;
int f[400], g[400];
long long ans = 1;
int work(int x)
{
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 0; x >> i > 0; i++)
	{
		swap(f, g);
		memset(f, 0, sizeof f);
		int l = 0;
		for (int j = 1; j <= x >> i; j *= 3)
		{
			l++;
		}
		for (int j = 0; g[j] > 0; j++)
		{
			for (int k = 0; q[k] < 1 << l; k++)
			{
				if ((q[j] & q[k]) == 0)
				{
					f[k] = (f[k] + g[j]) % mod;
				}
			}
		}
	}
	return f[0] + f[1];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 1 << 12; i++)
	{
		if ((i & i << 1) == 0)
		{
			q[c++] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 > 0 && i % 3 > 0)
		{
			ans = ans * work(n / i) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}