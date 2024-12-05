#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y;
vector<int> a;
vector<int> b;
int f[100020];
int g[100020];
int h[100020];
int Q(const vector<int> &a, int x)
{
	int i = lower_bound(a.begin(), a.end(), x) - a.begin();
	int mn = n;
	if (i < a.size())
	{
		mn = min(mn, a[i] - x);
	}
	if (i > 0)
	{
		mn = min(mn, x - a[i - 1]);
	}
	return mn;
}
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
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			f[i] = i;
			g[i] = n;
			h[i] = n;
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			U(x, y);
		}
		if (F(1) == F(n))
		{
			printf("%d\n", 0);
			continue;
		}
		a.clear();
		b.clear();
		for (int i = 1; i <= n; i++)
		{
			if (F(i) == F(1))
			{
				a.push_back(i);
			}
			if (F(i) == F(n))
			{
				b.push_back(i);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int fi = F(i);
			g[fi] = min(g[fi], Q(a, i));
			h[fi] = min(h[fi], Q(b, i));
		}
		long long z = (long long)n * n;
		for (int i = 1; i <= n; i++)
		{
			z = min(z, (long long)g[i] * g[i] + (long long)h[i] * h[i]);
		}
		printf("%lld\n", z);
	}
	return 0;
}