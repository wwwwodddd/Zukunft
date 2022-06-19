#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int f[200020];
int c[200020];
int d[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 200020; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		f[F(x)] = F(y + 100010);
	}
	for (int i = 0; i < 200020; i++)
	{
		if (i < 100010)
		{
			c[F(i)]++;
		}
		else
		{
			d[F(i)]++;
		}
	}
	long long z = -n;
	for (int i = 0; i < 200020; i++)
	{
		z += (long long)c[i] * d[i];
	}
	printf("%lld\n", z);
	return 0;
}