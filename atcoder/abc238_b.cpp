#include <bits/stdc++.h>
using namespace std;
int n, a[999], z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = (a[i] + a[i-1]) % 360;
	}
	sort(a, a + n + 1);
	a[n + 1] = 360;
	for (int i = 1; i <= n + 1; i++)
	{
		z = max(z, a[i] - a[i-1]);
	}
	cout << z << endl;
	return 0;
}