#include <bits/stdc++.h>
using namespace std;
map<long, long> g;
long F(long x)
{
	long re = 0;
	for (int i = 0; i < 60; i++)
	{
		if (x >> i & 1)
		{
			if (x >> (i + 1) & 1)
			{
				re |= 1l << i;
				i++;
			}
			else
			{
				re |= 3l << i;
			}
		}
	}
	return re;
}
int main()
{
	int n;
	long z = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		long x;
		scanf("%ld", &x);
		z += g[F(x)];
		g[x]++;
	}
	printf("%ld\n", z);
	return 0;
}