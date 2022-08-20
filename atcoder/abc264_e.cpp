#include <bits/stdc++.h>
using namespace std;
int n, m, e, q, g;
int u[500020];
int v[500020];
int r[500020];
int x[500020];
int z[500020];
int c[200020];
int d[200020];
int f[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return;
	}
	if (d[x] == 0 && d[y] > 0)
	{
		g += c[x];
	}
	if (d[y] == 0 && d[x] > 0)
	{
		g += c[y];
	}
	c[y] += c[x];
	d[y] += d[x];
	f[x] = y;
}
int main()
{
	scanf("%d%d%d", &n, &m, &e);
	for (int i = 1; i <= e; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		r[i] = 1;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &x[i]);
		r[x[i]] = 0;
	}
	for (int i = 1; i <= n + m; i++)
	{
		f[i] = i;
		if (i > n)
		{
			d[i] = 1;
		}
		else
		{
			c[i] = 1;
		}
	}
	for (int i = 1; i <= e; i++)
	{
		if (r[i] == 1)
		{
			U(u[i], v[i]);
		}
	}
	for (int i = q; i > 0; i--)
	{
		z[i] = g;
		U(u[x[i]], v[x[i]]);
	}
	for (int i = 1; i <= q; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}
