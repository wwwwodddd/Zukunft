#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const long long inf = 2e9;
int n, q;
pair<pair<int, int>, int> a[200020];
long long z[100020];
map<int, long long> f, g;
void insert(map<int, long long> &f, int x, long long y)
{
	if (y < f.lower_bound(x)->second)
	{
		f[x] = y;
		auto it = --f.lower_bound(x);
		while (it->second > y)
		{
			f.erase(it--);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i].X.X, &a[i].X.Y, &a[i].Y);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &a[i+n].X.X, &a[i+n].X.Y);
		z[i] = abs(a[i+n].X.X - a[i+n].X.Y);
		a[i+n].Y = -i - 1;
	}
	sort(a, a + n + q);
	f[-inf] = -2 * inf;
	f[inf] = 2 * inf;
	g = f;
	for (int i = 0; i < n + q; i++)
	{
		if (a[i].Y < 0)
		{
			z[-a[i].Y - 1] = min(z[-a[i].Y - 1], f.lower_bound(-a[i].X.Y)->second + a[i].X.X + a[i].X.Y);
			z[-a[i].Y - 1] = min(z[-a[i].Y - 1], g.lower_bound(a[i].X.Y)->second + a[i].X.X - a[i].X.Y);
		}
		else
		{
			insert(f, -a[i].X.Y, a[i].Y - a[i].X.X - a[i].X.Y);
			insert(g, a[i].X.Y, a[i].Y - a[i].X.X + a[i].X.Y);
		}
	}
	f.clear();
	f[-inf] = -2 * inf;
	f[inf] = 2 * inf;
	g = f;
	for (int i = n + q - 1; i >= 0; i--)
	{
		if (a[i].Y < 0)
		{
			z[-a[i].Y - 1] = min(z[-a[i].Y - 1], f.lower_bound(-a[i].X.Y)->second - a[i].X.X + a[i].X.Y);
			z[-a[i].Y - 1] = min(z[-a[i].Y - 1], g.lower_bound(a[i].X.Y)->second - a[i].X.X - a[i].X.Y);
		}
		else
		{
			insert(f, -a[i].X.Y, a[i].Y + a[i].X.X - a[i].X.Y);
			insert(g, a[i].X.Y, a[i].Y + a[i].X.X + a[i].X.Y);
		}
	}
	for (int i = 0; i < q; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}