#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[10020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int mn = 1e9;
		for (int j = i; j < n; j++)
		{
			mn = min(mn, a[j]);
			z = max(z, mn * (j - i + 1));
		}
	}
	cout << z << endl;
	return 0;
}
