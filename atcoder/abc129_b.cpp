#include <bits/stdc++.h>
using namespace std;
int n, a[120], s, t, z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t += a[i];
	}
	z = t;
	for (int i = 1; i < n; i++)
	{
		s += a[i];
		t -= a[i];
		z = min(z, abs(s - t));
	}
	cout << z << endl;
	return 0;
}
