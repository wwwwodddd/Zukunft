#include <bits/stdc++.h>
using namespace std;
int n, s, z = 1e9;
int a[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int j = 1; j < 84; j++)
	{
		s = 0;
		for (int i = 0; i < n; i++)
		{
			int d = max(max(a[i] - j, j - 17 - a[i]), 0);
			s += d * d;
		}
		z = min(z, s);
	}
	cout << z << endl;
	return 0;
}