#include <bits/stdc++.h>
using namespace std;
int n, m, l;
long long s, z;
int a[100020];
pair<int, int> b[100020];
int c[100020];
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		cin >> b[i].second >> b[i].first;
	}
	sort(b, b + m);
	for (int i = 0; i < l; i++)
	{
		cin >> c[i];
	}
	sort(c, c + l, greater<int>());
	for (int i = 0; i < n; i++)
	{
		s += c[i];
	}
	z = s;
	for (int i = n - 1, j = m - 1; i >= 0; i--)
	{
		s -= c[i];
		while (a[i] > 0 && j >= 0)
		{
			long long t = min(a[i], b[j].second);
			a[i] -= t;
			b[j].second -= t;
			s += b[j].first * t;
			z = max(z, s);
			if (b[j].second == 0)
			{
				j--;
			}
		}
	}
	cout << z << endl;
	return 0;
}