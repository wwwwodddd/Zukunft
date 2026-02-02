#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long f[40020];
int a[130], c[130];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	fill(f, f + 40000, 1);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		for (int j = 40000; j > 0; j--)
		{
			for (int k = 2; k <= a[i] && k * c[i] <= j; k++)
			{
				f[j] = max(f[j], min(f[j - k * c[i]] * k, m));
			}
		}
	}
	cout << (lower_bound(f, f + 40000, m) - f) << endl;
	return 0;
}