#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<pair<int, int>, int> a[200020];
int c[200020];
int f[200020];
int v[200020];
int z[200020];
int maxsize;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	c[x] += c[y];
	f[y] = x;
	maxsize = max(maxsize, c[x]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[m + i].first.first);
		a[m + i].second = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a[i].first.first, &a[i].first.second);
		a[i].second = i;
	}
	sort(a, a + n + m);
	for (int i = n + m - 1; i >= 0; i--)
	{
		if (a[i].first.second > 0)
		{
			z[a[i].second] = maxsize < a[i].first.second;
		}
		else
		{
			v[a[i].second] = 1;
			c[a[i].second] = 1;
			maxsize = max(maxsize, 1);
			f[a[i].second] = a[i].second;
			if (v[a[i].second - 1])
			{
				U(a[i].second, a[i].second - 1);
			}
			if (v[a[i].second + 1])
			{
				U(a[i].second, a[i].second + 1);
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}