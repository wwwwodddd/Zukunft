#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
long long F(int x, int y, int z, long long h)
{
	int i = 0;
	while (i < n && a[i] < h)
	{
		h += a[i++] / 2;
	}
	h *= x;
	while (i < n && a[i] < h)
	{
		h += a[i++] / 2;
	}
	h *= y;
	while (i < n && a[i] < h)
	{
		h += a[i++] / 2;
	}
	h *= z;
	while (i < n && a[i] < h)
	{
		h += a[i++] / 2;
	}
	return i;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long h;
		cin >> n >> h;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		cout << max(F(2, 2, 3, h), max(F(2, 3, 2, h), F(3, 2, 2, h))) << endl;
	}
	return 0;
}
