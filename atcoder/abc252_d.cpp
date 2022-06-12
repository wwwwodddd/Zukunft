#include <bits/stdc++.h>
using namespace std;
int n, x;
int c[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	long long z = n * (n - 1LL) * (n - 2) / 6;
	for (int i = 0; i < 200010; i++)
	{
		z -= c[i] * (c[i] - 1LL) * (c[i] - 2) / 6;
		z -= c[i] * (c[i] - 1LL) / 2 * (n - c[i]);
	}
	cout << z << endl;
	return 0;
}
