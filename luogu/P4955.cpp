#include <bits/stdc++.h>
using namespace std;
int n, m, s, ec;
int a[2500020];
int b[2500020];
int f[2500020];
pair<int, pair<int, int> > e[5000020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
long long z;
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		b[x] += b[y];
		f[y] = x;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n * m; i++)
	{
		scanf("%d", &b[i]);
		s += b[i];
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
		U(e[i].second.first, e[i].second.second);
		if (b[F(e[i].second.first)] == s)
		{
			printf("%lld\n", e[i].first);
			break;
		}
	}
	return 0;
}