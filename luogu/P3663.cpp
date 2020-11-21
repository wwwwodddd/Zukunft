#include <bits/stdc++.h>
using namespace std;
bool v[120][120];
bool a[120][120];
bool b[120][120];
int c[10020];
int f[10020];
int n, m, z;
int xa, ya, xb, yb;
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
		f[y] = x;
		c[x] += c[y];
	}
}
int main()
{
	scanf("%d%d%d", &n, &z, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		xa--;
		ya--;
		xb--;
		yb--;
		if (xa > xb)
		{
			swap(xa, xb);
		}
		if (ya > yb)
		{
			swap(ya, yb);
		}
		if (xa == xb)
		{
			a[xa][ya] = true;
		}
		if (ya == yb)
		{
			b[xa][ya] = true;
		}
	}
	for (int i = 0; i < z; i++)
	{
		scanf("%d%d", &xa, &ya);
		xa--;
		ya--;
		c[xa * n + ya] = 1;
	}
	for (int i = 0; i < n * n; i++)
	{
		f[i] = i;
	}
	z = z * (z - 1) / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n - 1 && !a[i][j])
			{
				U(i * n + j, i * n + j + 1);
			}
			if (i < n - 1 && !b[i][j])
			{
				U(i * n + j, i * n + j + n);
			}
		}
	}
	for (int i = 0; i < n * n; i++)
	{
		if (F(i) == i)
		{
			z -= c[i] * (c[i] - 1) / 2;
		}
	}
	printf("%d\n", z);
	return 0;
}