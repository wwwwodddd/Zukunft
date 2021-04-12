#include <bits/stdc++.h>
using namespace std;
int n, k, s, z;
int a[520];
int b[520];
bool ok(int x)
{
	int t = 0, r = 0;
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i] % x;
		t += b[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n - t / x; i++)
	{
		r += b[i];
	}
	return r <= k;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	for (int i = 1; i * i <= s; i++)
	{
		if (s % i == 0)
		{
			if (ok(i))
			{
				z = max(z, i);
			}
			if (ok(s / i))
			{
				z = max(z, s / i);
			}
		}
	}
	cout << z << endl;
	return 0;
}