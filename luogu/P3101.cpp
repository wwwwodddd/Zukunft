#include <bits/stdc++.h>
using namespace std;
int n, m, t, ec;
int a[2500020];
int b[2500020];
int c[2500020];
int f[2500020];
pair<int, pair<int, int> > e[5000020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
long long z;
void U(int x, int y, long long d)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		b[x] += b[y];
		c[x] += c[y];
		if (c[x] >= t)
		{
			z += b[x] * d;
			b[x] = 0;
		}
		f[y] = x;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n * m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n * m; i++)
	{
		scanf("%d", &b[i]);
		c[i] = 1;
		f[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			e[ec++] = make_pair(abs(a[i * m + j] - a[i * m + j - 1]), make_pair(i * m + j, i * m + j - 1));
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			e[ec++] = make_pair(abs(a[i * m + j] - a[i * m + j - m]), make_pair(i * m + j, i * m + j - m));
		}
	}
	sort(e, e + ec);
	for (int i = 0; i < ec; i++)
	{
		U(e[i].second.first, e[i].second.second, e[i].first);
	}
	printf("%lld\n", z);
	return 0;
}