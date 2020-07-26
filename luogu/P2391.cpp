#include <bits/stdc++.h>
using namespace std;
int f[1000020];
int c[1000020];
int n, m, p, q;
int F(int x)
{
	int r = x;
	while (r != f[r])
	{
		r = f[r];
	}
	while (x != f[x])
	{
		int p = f[x];
		f[x] = r;
		x = p;
	}
	return r;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &p, &q);
	for (int i = 1; i <= n + 1; i++)
	{
		f[i] = i;
	}
	for (int i = m; i > 0; i--)
	{
		int x = (i * p + q) % n + 1;
		int y = (i * q + p) % n + 1;
		if (x > y)
		{
			swap(x, y);
		}
		for (int j = F(x); j <= y; j = F(j))
		{
			c[j] = i;
			f[j] = j + 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", c[i]);
	}
	return 0;
}