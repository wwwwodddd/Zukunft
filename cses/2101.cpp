#include <bits/stdc++.h>
using namespace std;
int c[200020];
int f[200020];
int l[200020];
int n, m, q, x, y, z;
long long ans;
pair<int, pair<int, int> > a[200020];
void U(int x, int y, int z)
{
	while (x != f[x])
	{
		x = f[x];
	}
	while (y != f[y])
	{
		y = f[y];
	}
	if (x != y)
	{
		if (c[x] < c[y])
		{
			swap(x, y);
		}
		c[x] += c[y];
		f[y] = x;
		l[y] = z;
	}
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		c[i] = 1;
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].second.first >> a[i].second.second;
		a[i].first = i + 1;
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++)
	{
		U(a[i].second.first, a[i].second.second, a[i].first);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		z = 0;
		while (x != y)
		{
			if (c[x] > c[y])
			{
				swap(x, y);
			}
			z = max(z, l[x]);
			if (x == f[x])
			{
				z = -1;
				break;
			}
			x = f[x];
		}
		cout << z << endl;
	}
	return 0;
}