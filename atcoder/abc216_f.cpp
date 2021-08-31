#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, z;
pair<int, int> a[100020];
int f[5020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i <= 5000; i++)
	{
		f[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i].first >= a[i].second)
		{
			z = (z + f[a[i].first - a[i].second]) % p;
		}
		for (int j = 5000; j >= a[i].second; j--)
		{
			f[j] = (f[j] + f[j - a[i].second]) % p;
		}
	}
	cout << z << endl;
	return 0;
}