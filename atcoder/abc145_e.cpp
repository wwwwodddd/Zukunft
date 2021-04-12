#include <bits/stdc++.h>
using namespace std;
int n, t, z;
int f[7777];
pair<int, int> a[7777];
int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = t - 1; j >= 0; j--)
		{
			f[j + a[i].first] = max(f[j + a[i].first], f[j] + a[i].second);
			z = max(z, f[j + a[i].first]);
		}
	}
	cout << z << endl;
	return 0;
}