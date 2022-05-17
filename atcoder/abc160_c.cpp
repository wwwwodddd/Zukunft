#include <bits/stdc++.h>
using namespace std;
int k, n, z;
int a[200020];
int main()
{
	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	z = k + a[0] - a[n - 1];
	for (int i = 1; i < n; i++)
	{
		z = max(z, a[i] - a[i - 1]);
	}
	cout << k - z << endl;
	return 0;
}
