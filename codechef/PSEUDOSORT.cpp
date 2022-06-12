#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int z = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				z++;
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				z++;
			}
		}
		cout << (z > 1 ? "NO" : "YES") << endl;
	}
	return 0;
}