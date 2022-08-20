#include <bits/stdc++.h>
using namespace std;
int n, k, z = 1e9;
int a[100020];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i + k - 1 < n; i++)
	{
		z = min(z, a[i + k - 1] - a[i]);
	}
	cout << z << endl;
	return 0;
}
