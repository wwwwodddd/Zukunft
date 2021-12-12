#include <bits/stdc++.h>
using namespace std;
int n, s, z;
int a[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	s = (s + n / 2) / n;
	for (int i = 0; i < n; i++)
	{
		z += (a[i] - s) * (a[i] - s);
	}
	cout << z << endl;
	return 0;
}
