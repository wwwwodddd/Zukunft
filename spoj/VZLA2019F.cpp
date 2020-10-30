#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int a[100020];
int b[100020];
long long c[100020];
int f[100020];
int o[100020];
int p[100020];
int q[100020];
int v[100020];
int w[100020];
long long z[100020];
multiset<long long> s;
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
		s.erase(s.find(c[x]));
		s.erase(s.find(c[y]));
		f[x] = y;
		c[y] += c[x];
		s.insert(c[y]);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &o[i]);
		if (o[i] == 1)
		{
			scanf("%d", &p[i]);
			v[p[i]] = 1;
		}
		else
		{
			scanf("%d%d", &p[i], &q[i]);
			swap(q[i], w[p[i]]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = w[i];
		s.insert(c[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		if (!v[i])
		{
			U(a[i], b[i]);
		}
	}
	for (int i = l; i--;)
	{
		z[i] = *--s.end();
		if (o[i] == 1)
		{
			U(a[p[i]], b[p[i]]);
		}
		else
		{
			s.erase(s.find(c[F(p[i])]));
			c[F(p[i])] += q[i] - w[p[i]];
			s.insert(c[F(p[i])]);
			w[p[i]] = q[i];
		}
	}
	for (int i = 0; i < l; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}