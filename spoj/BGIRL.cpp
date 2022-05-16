#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y;
int f[100020];
int c[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		f[x] = y;
		c[y] += c[x];
	}
}
bool P(int x)
{
	if (x < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
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
			U(x, y);
		}
		int z = -1;
		for (int i = 1; i <= n; i++)
		{
			if (f[i] == i && P(c[i]))
			{
				z = max(z, c[i]);
			}
		}
		printf("%d\n", z);
	}
	return 0;
}