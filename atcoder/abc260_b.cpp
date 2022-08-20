#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
pair<int, int> a[1020];
pair<int, int> b[1020];
pair<int, int> c[1020];
int v[1020];
int main()
{
	cin >> n >> x >> y >> z;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i].first;
		a[i].first = -a[i].first;
		b[i].first = -b[i].first;
		c[i].first = a[i].first + b[i].first;
		a[i].second = b[i].second = c[i].second = i + 1;
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	for (int i = 0; i < n; i++)
	{
		if (v[a[i].second] == 0 && x > 0)
		{
			v[a[i].second] = 1;
			x--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (v[b[i].second] == 0 && y > 0)
		{
			v[b[i].second] = 1;
			y--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (v[c[i].second] == 0 && z > 0)
		{
			v[c[i].second] = 1;
			z--;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i])
		{
			cout << i << endl;
		}
	}
	return 0;
}
