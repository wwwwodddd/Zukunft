#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200020];
int b[200020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] -= b[i];
		a[i] += a[i - 1];
	}
	sort(a, a + n);
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		z += abs(a[i] - a[n / 2]);
	}
	cout << z << endl;
	return 0;
}