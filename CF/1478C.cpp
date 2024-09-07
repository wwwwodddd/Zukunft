#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[200020];
long long d[200020];
bool ok()
{
	sort(d, d + 2 * n);
	for (int i = 0; i < 2 * n; i += 2)
	{
		if (d[i] != d[i + 1])
		{
			return false;
		}
	}
	for (int i = 0; i + 2 < 2 * n; i += 2)
	{
		if (d[i] == d[i + 2])
		{
			return false;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		// a[i + 1] - a[i];
		if ((d[2 * i + 2] - d[2 * i]) % (2 * i + 2) != 0)
		{
			return false;
		}
		a[i + 1] = (d[2 * i + 2] - d[2 * i]) / (2 * i + 2);
	}
	long long s = d[0];
	for (int i = 1; i < n; i++)
	{
		s -= a[i] * (n - i) * 2;
	}
	if (s <= 0 || s % (2 * n) != 0)
	{
		return false;
	}
	a[0] = s / (2 * n);
	for (int i = 1; i < n; i++)
	{
		a[i] += a[i - 1];
	}
	return true;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> d[i];
		}
		cout << (ok() ? "YES" : "NO") << endl;
	}
	return 0;
}