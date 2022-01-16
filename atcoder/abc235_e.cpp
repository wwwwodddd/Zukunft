#include <bits/stdc++.h>
using namespace std;
int n, m, q;
pair<pair<int, int>, pair<int, int> > a[400020];
int f[200020];
int z[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	f[F(x)] = F(y);
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = q; i < q + m; i++)
	{
		cin >> a[i].second.first >> a[i].second.second >> a[i].first.first;
		a[i].first.second = -1;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> a[i].second.first >> a[i].second.second >> a[i].first.first;
		a[i].first.second = i;
	}
	sort(a, a + m + q);
	for (int i = 0; i < m + q; i++)
	{
		if (a[i].first.second == -1)
		{
			U(a[i].second.first, a[i].second.second);
		}
		else
		{
			z[a[i].first.second] = F(a[i].second.first) != F(a[i].second.second);
		}
	}
	for (int i = 0; i < q; i++)
	{
		cout << (z[i] ? "Yes" : "No") << endl;
	}
	return 0;
}
