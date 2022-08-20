#include <bits/stdc++.h>
using namespace std;
int n, m, e, q;
int u[500020];
int v[500020];
int r[500020];
int x[500020];
int z[500020];
int c[200020];
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
	c[y] += c[x];
	f[x] = y;
}
int main()
{
	scanf("%d%d%d", &n, &m, &e);
	for (int i = 1; i <= e; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		if (u[i] > n)
		{
			u[i] = 0;
		}
		if (v[i] > n)
		{
			v[i] = 0;
		}
		r[i] = 1;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &x[i]);
		r[x[i]] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
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
		z[i] = c[F(0)];
		U(u[x[i]], v[x[i]]);
	}
	for (int i = 1; i <= q; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}
