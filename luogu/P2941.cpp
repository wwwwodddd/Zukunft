#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[520];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int d[520][520];
int a[520], c;
int main()
{
	cin >> n;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		d[i][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		f[F(x)] = F(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (F(i) == i)
		{
			a[c++] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &x);
			d[f[i]][f[j]] = min(d[f[i]][f[j]], x);
		}
	}
	int z = 1e9;
	for (int i = 0; i < c; i++)
	{
		int s = 0;
		for (int j = 0; j < c; j++)
		{
			s += d[a[i]][a[j]];
		}
		z = min(z, s);
	}
	printf("%d\n", z * 2);
	return 0;
}