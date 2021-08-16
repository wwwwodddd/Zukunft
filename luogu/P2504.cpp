#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int b[520];
int f[1020];
int x[1020];
int y[1020];
pair<int, pair<int, int> > a[500020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> b[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		f[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			a[m++] = make_pair((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), make_pair(i, j));
		}
	}
	sort(a, a + m);
	int z = 0, c = 0;
	for (int i = 0; i < m; i++)
	{
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y)
		{
			f[x] = y;
			z = a[i].first;
		}
	}
	for (int i = 0; i < q; i++)
	{
		if (b[i] * b[i] >= z)
		{
			c++;
		}
	}
	cout << c << endl;
	return 0;
}
