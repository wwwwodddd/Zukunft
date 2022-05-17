#include <bits/stdc++.h>
using namespace std;
int n, s, t, z;
int a[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	z = s;
	for (int i = 0; i < n; i++)
	{
		t += a[i];
		z = min(z, abs(2 * t - s));
	}
	cout << z << endl;
	return 0;
}
