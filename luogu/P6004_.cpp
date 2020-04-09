#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[100020];
int x[100020];
int y[100020];
int z[100020];
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
}
bool ok(int M)
{
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		if (z[i] >= M)
		{
			U(x[i], y[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (F(i) != F(p[i]))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	}
	int L = 0;
	int R = 1e9 + 7;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	if (L > 1e9)
	{
		L = -1;
	}
	printf("%d\n", L);
	return 0;
}