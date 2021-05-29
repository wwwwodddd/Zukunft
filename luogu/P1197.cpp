#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, y;
vector<int> a[400020];
int f[400020];
int p[400020];
int v[400020];
int z[400020];
int c;
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
		c--;
	}
	f[x] = y;
}
void gao(int x)
{
	c++;
	v[x] = 0;
	for (int i: a[x])
	{
		if (!v[i])
		{
			U(x, i);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &p[i]);
		v[p[i]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!v[i])
		{
			gao(i);
		}
	}
	z[l] = c;
	for (int i = l - 1; i >= 0; i--)
	{
		gao(p[i]);
		z[i] = c;
	}
	for (int i = 0; i <= l; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}