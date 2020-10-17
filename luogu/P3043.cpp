#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int f[100020];
int c[100020];
int d[100020];
int n, m, x, y;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		x = F(x);
		y = F(y);
		d[x]++;
		if (x != y)
		{
			f[y] = x;
			c[x] += c[y];
			d[x] += d[y];
		}
	}
	int z = 1;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			if (d[i] < c[i])
			{
				z = (long long)z * c[i] % mod;
			}
			else if (d[i] == c[i])
			{
				z = z * 2 % mod;
			}
			else
			{
				z = 0;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}