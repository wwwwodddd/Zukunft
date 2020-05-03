#include <bits/stdc++.h>
using namespace std;
int c[10020];
int f[10020];
int l[10020];
int n, m, q, x, y, z;
long long ans;
pair<int, pair<int, int> > a[50020];
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
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		c[i] = 1;
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a, a + m);
	for (int i = m - 1; i >= 0; i--) {
		U(a[i].second.first, a[i].second.second, a[i].first);
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		z = 100000;
		while (x != y)
		{
			if (c[x] > c[y])
			{
				swap(x, y);
			}
			z = min(z, l[x]);
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