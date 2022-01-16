#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200020], s, z;
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
		s -= 2 * a[i];
		z = min(z, abs(s));
	}
	cout << z << endl;
	return 0;
}
