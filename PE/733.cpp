#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
const int q = 10000019;
int n;
int c[10000020];
int d[10000020];
int a[1000020];
long long f[4][1000020];
long long g[4][1000020];
void change(int *c, int x, int y)
{
	for (x++; x <= q; x += x & -x)
	{
		c[x] = (c[x] + y) % p;
	}
}
int query(int *c, int x)
{
	int re = 0;
	for (x++; x > 0; x -= x & -x)
	{
		re = (re + c[x]) % p;
	}
	return re;
}
int main()
{
	n = 1000000;
	a[0] = 1;
	for (int j = 1; j <= n; j++)
	{
		a[j] = a[j - 1] * 153 % q;
		g[0][j] = 1;
		f[0][j] = a[j];
	}
	int s = 0;
	for (int i = 1; i < 4; i++)
	{
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = query(c, a[j] - 1);
			f[i][j] = query(d, a[j] - 1);
			change(c, a[j], g[i - 1][j]);
			change(d, a[j], f[i - 1][j]);
			f[i][j] = (f[i][j] + g[i][j] * a[j]) % p;
			if (i == 3)
			{
				s = (s + f[i][j]) % p;
			}
		}
	}
	printf("%d\n", s);
	return 0;
}