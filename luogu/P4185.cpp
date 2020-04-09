#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, pair<int, int> > a[200020];
int f[100020];
int c[100020];
int z[100020];
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
		f[x] = y;
		c[y] += c[x];
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d", &a[m + i].second.first, &a[m + i].second.second, &a[m + i].first);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second.second);
		a[i].second.first = -i;
	}
	sort(a, a + m + n - 1);
	for (int i = m + n - 2; i >= 0; i--)
	{
		if (a[i].second.first > 0)
		{
			U(a[i].second.first, a[i].second.second);
		}
		else
		{
			z[-a[i].second.first] = c[F(a[i].second.second)] - 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}