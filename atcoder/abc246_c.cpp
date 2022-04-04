#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int a[200020];
long long z;
int main()
{
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		int t = min(a[i] / x, k);
		a[i] -= x * t;
		k -= t;
	}
	sort(a, a + n);
	for (int i = 0; i < n - k; i++)
	{
		z += a[i];
	}
	cout << z << endl;
	return 0;
}
